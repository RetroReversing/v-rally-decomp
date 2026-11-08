typedef struct {
    s32 errStatus;
    s32 dramAddr;
    s32 C2Addr;
    s32 sectorSize;
    u32 C1ErrNum;
    s32 C1ErrSector[4];
} DiskBlock;
typedef struct {
    s32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    s32 pad0C;
    s32 bmCtlShadow;
    s32 pad14;
    DiskBlock block[2];
} DiskXfer;
extern void func_800932E0(void*,s32,u32,s32,s32);
extern s32 D_800A1CD0;
extern u8 *D_800B5AF8;
extern void __osLeoResume(void),__osLeoAbnormalResume(void);

#define PI_STATUS (*(volatile s32 *)0xA4600010)
#define LEO_STATUS (*(volatile s32 *)0xA5000508)
#define LEO_BM_CTL (*(volatile s32 *)0xA5000510)
#define WAITIO(x) x = PI_STATUS; while (x & 3) { x = PI_STATUS; }

/* Disk drive (LEO) interrupt step. Advances the current read/seek transfer by
 * one step: checks the drive status, handles the error and bus-mode bits,
 * starts the next DMA into the block's DRAM buffer, and marks the block's
 * errStatus. Returns 1 while the transfer is still running, 0 when the drive
 * has finished, and resumes or aborts the LEO command when it is done. */
s32 func_8008FBC0(void) {
    volatile s32 pi_status;
    s32 status;
    u32 bm_ctl;
    DiskXfer *xfer;
    DiskBlock *blk;
    DiskBlock *blk0;
    s32 *c2;

    xfer = (DiskXfer *)(D_800B5AF8 + 0x14);
    blk = &xfer->block[xfer->blockNum];
    pi_status = PI_STATUS;
    if (pi_status & 1) {
        blk->errStatus = 0x1D;
        D_800A1CD0 &= ~0x800;
        __osLeoResume();
        return 1;
    }
    WAITIO(pi_status);
    status = LEO_STATUS;
    if (status & 0x02000000) {
        WAITIO(pi_status);
        LEO_BM_CTL = xfer->bmCtlShadow | 0x01000000;
        blk->errStatus = 0;
        return 0;
    }
    if (xfer->cmdType == 2) return 1;
    if (status & 0x08000000) {
        WAITIO(pi_status);
        status = LEO_STATUS;
        blk->errStatus = 0x16;
        __osLeoResume();
        PI_STATUS = 2;
        D_800A1CD0 |= 0x100401;
        return 1;
    }
    if (xfer->cmdType == 1) {
        if (!(status & 0x40000000)) {
            if (xfer->sectorNum + 1 != xfer->transferMode * 0x55) {
                blk->errStatus = 0x18;
                __osLeoAbnormalResume();
                return 1;
            }
            PI_STATUS = 2;
            D_800A1CD0 |= 0x100401;
            blk->errStatus = 0;
            __osLeoResume();
            return 1;
        }
        blk->dramAddr += blk->sectorSize;
        xfer->sectorNum++;
        func_800932E0(D_800B5AF8, 1, 0x05000400, blk->dramAddr, blk->sectorSize);
        return 1;
    }
    if (xfer->cmdType == 0) {
        if (xfer->transferMode == 3) {
            if ((s32)blk->C1ErrNum + 0x11 < xfer->sectorNum) {
                blk->errStatus = 0;
                __osLeoAbnormalResume();
                return 1;
            }
            if (!(status & 0x40000000)) {
                blk->errStatus = 0x17;
                __osLeoAbnormalResume();
                return 1;
            }
        } else {
            blk->dramAddr += blk->sectorSize;
        }
        bm_ctl = LEO_BM_CTL;
        if (((bm_ctl & 0x200000) && (bm_ctl & 0x400000)) || (bm_ctl & 0x02000000)) {
            if (blk->C1ErrNum > 3) {
                if (xfer->transferMode != 3 || xfer->sectorNum > 0x52) {
                    blk->errStatus = 0x17;
                    __osLeoAbnormalResume();
                    return 1;
                }
            } else {
                blk->C1ErrSector[blk->C1ErrNum] = xfer->sectorNum + 1;
            }
            blk->C1ErrNum++;
        }
        if (status & 0x10000000) {
            if (xfer->sectorNum + 1 != 0x58) {
                blk->errStatus = 0x18;
                __osLeoAbnormalResume();
            }
            if (xfer->transferMode == 2 && xfer->blockNum == 0) {
                xfer->blockNum = 1;
                xfer->sectorNum = -1;
                xfer->block[1].dramAddr -= xfer->block[1].sectorSize;
                blk->errStatus = 0x16;
            } else {
                PI_STATUS = 2;
                D_800A1CD0 |= 0x100401;
                xfer->cmdType = 2;
                blk->errStatus = 0;
            }
            func_800932E0(D_800B5AF8, 0, 0x05000000, blk->C2Addr, blk->sectorSize * 4);
            return 1;
        }
        if (xfer->sectorNum == -1 && xfer->transferMode == 2 && xfer->blockNum == 1) {
            blk0 = &xfer->block[0];
            if (blk0->C1ErrNum == 0) {
                c2 = (s32 *)blk0->C2Addr;
                if (c2[0] | c2[1] | c2[2] | c2[3]) {
                    blk0->errStatus = 0x17;
                    __osLeoAbnormalResume();
                    return 1;
                }
            }
            blk0->errStatus = 0;
            __osLeoResume();
        }
        xfer->sectorNum++;
        if (status & 0x40000000) {
            if (xfer->sectorNum > 0x54) {
                blk->errStatus = 0x18;
                __osLeoAbnormalResume();
                return 1;
            }
            func_800932E0(D_800B5AF8, 0, 0x05000400, blk->dramAddr, blk->sectorSize);
            blk->errStatus = 0;
            return 1;
        }
        if (xfer->sectorNum < 0x55) {
            blk->errStatus = 0x18;
            __osLeoAbnormalResume();
            return 1;
        }
        return 1;
    }
    blk->errStatus = 4;
    __osLeoAbnormalResume();
    return 1;
}
