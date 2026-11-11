typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;
typedef s32 OSPri;
typedef s32 OSId;
typedef struct OSThread_s OSThread;
extern void     osYieldThread(void);
extern s32      osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32      osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void     __osSetGlobalIntMask(u32);
extern void     __osResetGlobalIntMask(u32);
extern s32 func_80093640 (struct OSPiHandle_s *, u32 , u32);
extern s32 pi_read_word (struct OSPiHandle_s *, u32 , u32 *);

typedef struct {
    u32      errStatus;
    void    *dramAddr;
    void    *C2Addr;
    u32      sectorSize;
    u32      C1ErrNum;
    u32      C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
    u32             cmdType;
    u16             transferMode;
    u16             blockNum;
    s32             sectorNum;
    u32             devAddr;
    u32             bmCtlShadow;
    u32             seqCtlShadow;
    __OSBlockInfo   block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8                   type;
    u8                   latency;
    u8                   pageSize;
    u8                   relDuration;
    u8                   pulse;
    u8                   domain;
    u32                  baseAddress;
    u32                  speed;
    __OSTranxInfo        transferInfo;
} OSPiHandle;

typedef struct {
    u16          type;
    u8           pri;
    u8           status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    OSIoMesgHdr  hdr;
    void        *dramAddr;
    u32          devAddr;
    u32          size;
    OSPiHandle  *piHandle;
} OSIoMesg;

typedef struct {
    s32          active;
    OSThread    *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32         (*dma)(s32, u32, void *, u32);
    s32         (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

/* Register addresses and bits used by the 64DD (LeoDisk) block-transfer path. */
#define PI_STATUS_REG_ADDR   (0x04600000 + 0x10)
#define PI_STATUS_CLR_INTR   (1 << 1)
#define LEO_STATUS_REG       (0x05000000 + 0x508)
#define LEO_BM_CTL_REG       (0x05000000 + 0x510)
#define LEO_INTR_MASK       0x00100401
#define LEO_ERR_SECTOR_SKIP  29
#define LEO_BM_CTL_RESET     0x10000000
#define LEO_BM_CTL_STOP      0x01000000
#define LEO_BM_CTL_FAST      0x80000000
#define LEO_BM_STAT_BUSY     0x02000000
#define OS_MESG_TYPE_LOOPBACK  (10 + 0)
#define OS_MESG_TYPE_DMAREAD   (10 + 1)
#define OS_MESG_TYPE_DMAWRITE  (10 + 2)
#define OS_MESG_TYPE_EDMAREAD  (10 + 5)
#define OS_MESG_TYPE_EDMAWRITE (10 + 6)

/* Device manager thread: takes PI requests off the command queue. 64DD (type 2) block
   transfers run here, with retries and the access-queue handshake; everything else goes
   through the dma/edma hooks of the device manager. Replies go to each request's queue. */
void __osDevMgrMain(void* args) {
    OSIoMesg* iomsg;
    OSMesg evt;
    OSMesg dummy;
    s32 ret;
    OSDevMgr* dm;
    s32 retry_read = 0;

    dm = (OSDevMgr*)args;
    iomsg = 0;
    ret = 0;

    while (1) {
        osRecvMesg(dm->cmdQueue, (OSMesg)&iomsg, 1);

        if (iomsg->piHandle != 0 && iomsg->piHandle->type == 2 &&
            (iomsg->piHandle->transferInfo.cmdType == 0 ||
             iomsg->piHandle->transferInfo.cmdType == 1)) {
            __OSBlockInfo* blockInfo;
            __OSTranxInfo* info;
            info = &iomsg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;

            if (info->transferMode != 3) {
                blockInfo->dramAddr = (void*)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }

            if (info->transferMode == 2 && iomsg->piHandle->transferInfo.cmdType == 0) {
                retry_read = 1;
            } else {
                retry_read = 0;
            }

            osRecvMesg(dm->acsQueue, &dummy, 1);
            __osResetGlobalIntMask(LEO_INTR_MASK);
            func_80093640(iomsg->piHandle, LEO_BM_CTL_REG, (info->bmCtlShadow | LEO_BM_CTL_FAST));

        readblock1:
            osRecvMesg(dm->evtQueue, &evt, 1);
            info = &iomsg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];

            if (blockInfo->errStatus == LEO_ERR_SECTOR_SKIP) {
                u32 piStat;
                func_80093640(iomsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_RESET);
                func_80093640(iomsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow);
                pi_read_word(iomsg->piHandle, LEO_STATUS_REG, &piStat);

                if (piStat & LEO_BM_STAT_BUSY) {
                    func_80093640(iomsg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_STOP);
                }

                blockInfo->errStatus = 4;
                (*(volatile u32 *)((u32)(PI_STATUS_REG_ADDR) | 0xA0000000) = (u32)(PI_STATUS_CLR_INTR));
                __osSetGlobalIntMask(LEO_INTR_MASK | 0x00000800);
            }

            osSendMesg(iomsg->hdr.retQueue, iomsg, 0);

            if (retry_read == 1 && iomsg->piHandle->transferInfo.block[0].errStatus == 0) {
                retry_read = 0;
                goto readblock1;
            }

            osSendMesg(dm->acsQueue, 0, 0);
            if (iomsg->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (iomsg->hdr.type) {
                case OS_MESG_TYPE_DMAREAD:
                    osRecvMesg(dm->acsQueue, &dummy, 1);
                    ret = dm->dma(0, iomsg->devAddr, iomsg->dramAddr, iomsg->size);
                    break;
                case OS_MESG_TYPE_DMAWRITE:
                    osRecvMesg(dm->acsQueue, &dummy, 1);
                    ret = dm->dma(1, iomsg->devAddr, iomsg->dramAddr, iomsg->size);
                    break;
                case OS_MESG_TYPE_EDMAREAD:
                    osRecvMesg(dm->acsQueue, &dummy, 1);
                    ret = dm->edma(iomsg->piHandle, 0, iomsg->devAddr, iomsg->dramAddr, iomsg->size);
                    break;
                case OS_MESG_TYPE_EDMAWRITE:
                    osRecvMesg(dm->acsQueue, &dummy, 1);
                    ret = dm->edma(iomsg->piHandle, 1, iomsg->devAddr, iomsg->dramAddr, iomsg->size);
                    break;
                case OS_MESG_TYPE_LOOPBACK:
                    osSendMesg(iomsg->hdr.retQueue, iomsg, 0);
                    ret = -1;
                    break;
                default:
                    ret = -1;
                    break;
            }

            if (ret == 0) {
                osRecvMesg(dm->evtQueue, &evt, 1);
                osSendMesg(iomsg->hdr.retQueue, iomsg, 0);
                osSendMesg(dm->acsQueue, 0, 0);
            }
        }
    }
}
