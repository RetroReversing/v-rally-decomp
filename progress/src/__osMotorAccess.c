typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;
typedef struct { int status; OSMesgQueue *queue; int channel; } OSPfs;
typedef struct { u32 ramarray[15]; u32 pifstatus; } OSPifRam;
typedef struct {
      u8 dummy;
      u8 txsize;
      u8 rxsize;
      u8 cmd;
      u8 addrh;
      u8 addrl;
      u8 data[32];
      u8 datacrc;
} __OSContRamReadFormat;

extern u8 D_800C3520;
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern s32 __osSiRawStartDma(s32, void *);
void pif_lock(void);
void pif_unlock(void);
static OSPifRam __MotorDataBuf[4] __attribute__((aligned(8)));

/* Runs one rumble-pak command on the channel's 32-byte block. flag is the fill byte:
   0 switches the motor off (expects CRC 0), anything else switches it on (expects CRC
   0xEB). Returns 0 on success, 4 if the CRC is wrong, 5 if no pak is plugged in. */
s32 __osMotorAccess(OSPfs *pfs, s32 flag) {
    int i;
    s32 ret;
    u8 *block = (u8 *)&__MotorDataBuf[pfs->channel];

    if (!(pfs->status & 0x8)) {
        return 5;
    }

    pif_lock();
    __MotorDataBuf[pfs->channel].pifstatus = 1;
    block += pfs->channel;

    for (i = 0; i < 32; i++) {
        ((__OSContRamReadFormat *)block)->data[i] = flag;
    }

    D_800C3520 = 0xfe;
    __osSiRawStartDma(1, &__MotorDataBuf[pfs->channel]);
    osRecvMesg(pfs->queue, 0, 1);
    ret = __osSiRawStartDma(0, &__MotorDataBuf[pfs->channel]);
    osRecvMesg(pfs->queue, 0, 1);

    ret = ((__OSContRamReadFormat *)block)->rxsize & 0xC0;
    if (!ret) {
        if (!flag) {
            if (((__OSContRamReadFormat *)block)->datacrc != 0) {
                ret = 0x4;
            }
        } else {
            if (((__OSContRamReadFormat *)block)->datacrc != 0xEB) {
                ret = 0x4;
            }
        }
    }

    pif_unlock();

    return ret;
}
