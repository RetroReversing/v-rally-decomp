typedef struct OSMesgQueue_s OSMesgQueue;
typedef struct { u32 ramarray[15]; u32 pifstatus; } OSPifRam;
typedef struct { u8 dummy; u8 txsize; u8 rxsize; u8 cmd; u8 addrh; u8 addrl; u8 data[32]; u8 datacrc; } __OSContRamReadFormat;
typedef struct {
    s32 status;
    OSMesgQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
} OSPfs;

extern s32 __osPfsSelectBank(OSPfs *pfs, u8 bank);
extern s32 __osContRamRead(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
extern u8 __osContAddressCrc(u16 addr);
static OSPifRam __MotorDataBuf[4] __attribute__((aligned(8)));

/* Writes the motor-pak init request for one controller slot into the PIF buffer. */
static __inline__ void __osMakeMotorData(int channel, OSPifRam *mdata) {
    u8 *ptr = (u8 *)mdata->ramarray;
    __OSContRamReadFormat ramreadformat;
    int i;

    ramreadformat.dummy = 0xff;
    ramreadformat.txsize = 35;
    ramreadformat.rxsize = 1;
    ramreadformat.cmd = 3;
    ramreadformat.addrh = ((0xC000) / 32) >> 3;
    ramreadformat.addrl = (u8)(__osContAddressCrc(((0xC000) / 32)) | (((0xC000) / 32) << 5));

    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr++ = 0;
        }
    }

    *((__OSContRamReadFormat *)(ptr)) = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    ptr[0] = 0xfe;
}

/* Initialises the motor pak on a controller: selects the bank, reads the
 * identity block and, if the pak is not already set up, writes the motor data. */
s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel) {
    s32 ret;
    u8 temp[32];

    pfs->queue = mq;
    pfs->channel = channel;
    pfs->activebank = 0xFF;
    pfs->status = 0;

    ret = __osPfsSelectBank((pfs), (0xFE));

    if (ret == 2) {
        ret = __osPfsSelectBank((pfs), (0x80));
    }

    if (ret != 0) {
        return ret;
    }

    ret = __osContRamRead(mq, channel, ((0x8000) / 32), temp);

    if (ret == 2) {
        ret = 0x4;
    }

    if (ret != 0) {
        return ret;
    } else if (temp[31] == 254) {
        return 11;
    }

    ret = __osPfsSelectBank((pfs), (0x80));
    if (ret == 2) {
        ret = 0x4;
    }

    if (ret != 0) {
        return ret;
    }

    ret = __osContRamRead(mq, channel, ((0x8000) / 32), temp);
    if (ret == 2) {
        ret = 0x4;
    }

    if (ret != 0) {
        return ret;
    } else if (temp[31] != 0x80) {
        return 11;
    }

    if (!(pfs->status & 0x8)) {
        __osMakeMotorData(channel, &__MotorDataBuf[channel]);
    }

    pfs->status = 0x8;
    return 0;
}
