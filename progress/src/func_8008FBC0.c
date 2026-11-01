typedef struct {
    s32 errStatus;
    s32 dramAddr;
    s32 C2Addr;
    s32 sectorSize;
    u32 C1ErrNum;
    s32 C1ErrSector[4];
} Blk;
typedef struct {
    s32 cmdType;
    u16 transferMode;
    u16 blockNum;
    s32 sectorNum;
    s32 pad0C;
    s32 bmCtlShadow;
    s32 pad14;
    Blk block[2];
} Info;
extern void func_800932E0(void*,s32,u32,s32,s32);
extern s32 D_800A1CD0;
extern u8 *D_800B5AF8;
extern void __osLeoResume(void),__osLeoAbnormalResume(void);

#define PI_ST (*(volatile s32 *)0xA4600010)
#define WAITIO(x) x = PI_ST; while (x & 3) { x = PI_ST; }

s32 func_8008FBC0(void) {
    volatile s32 pi;
    s32 stat;
    u32 bm;
    Info *info;
    Blk *b;
    Blk *b0;
    s32 *c2;

    info = (Info *)(D_800B5AF8 + 0x14);
    b = &info->block[info->blockNum];
    pi = PI_ST;
    if (pi & 1) {
        b->errStatus = 0x1D;
        D_800A1CD0 &= ~0x800;
        __osLeoResume();
        return 1;
    }
    WAITIO(pi);
    stat = *(volatile s32 *)0xA5000508;
    if (stat & 0x02000000) {
        WAITIO(pi);
        *(volatile s32 *)0xA5000510 = info->bmCtlShadow | 0x01000000;
        b->errStatus = 0;
        return 0;
    }
    if (info->cmdType == 2) return 1;
    if (stat & 0x08000000) {
        WAITIO(pi);
        stat = *(volatile s32 *)0xA5000508;
        b->errStatus = 0x16;
        __osLeoResume();
        PI_ST = 2;
        D_800A1CD0 |= 0x100401;
        return 1;
    }
    if (info->cmdType == 1) {
        if (!(stat & 0x40000000)) {
            if (info->sectorNum + 1 != info->transferMode * 0x55) {
                b->errStatus = 0x18;
                __osLeoAbnormalResume();
                return 1;
            }
            PI_ST = 2;
            D_800A1CD0 |= 0x100401;
            b->errStatus = 0;
            __osLeoResume();
            return 1;
        }
        b->dramAddr += b->sectorSize;
        info->sectorNum++;
        func_800932E0(D_800B5AF8, 1, 0x05000400, b->dramAddr, b->sectorSize);
        return 1;
    }
    if (info->cmdType == 0) {
        if (info->transferMode == 3) {
            if ((s32)b->C1ErrNum + 0x11 < info->sectorNum) {
                b->errStatus = 0;
                __osLeoAbnormalResume();
                return 1;
            }
            if (!(stat & 0x40000000)) {
                b->errStatus = 0x17;
                __osLeoAbnormalResume();
                return 1;
            }
        } else {
            b->dramAddr += b->sectorSize;
        }
        bm = *(volatile s32 *)0xA5000510;
        if (((bm & 0x200000) && (bm & 0x400000)) || (bm & 0x02000000)) {
            if (b->C1ErrNum > 3) {
                if (info->transferMode != 3 || info->sectorNum > 0x52) {
                    b->errStatus = 0x17;
                    __osLeoAbnormalResume();
                    return 1;
                }
            } else {
                b->C1ErrSector[b->C1ErrNum] = info->sectorNum + 1;
            }
            b->C1ErrNum++;
        }
        if (stat & 0x10000000) {
            if (info->sectorNum + 1 != 0x58) {
                b->errStatus = 0x18;
                __osLeoAbnormalResume();
            }
            if (info->transferMode == 2 && info->blockNum == 0) {
                info->blockNum = 1;
                info->sectorNum = -1;
                info->block[1].dramAddr -= info->block[1].sectorSize;
                b->errStatus = 0x16;
            } else {
                PI_ST = 2;
                D_800A1CD0 |= 0x100401;
                info->cmdType = 2;
                b->errStatus = 0;
            }
            func_800932E0(D_800B5AF8, 0, 0x05000000, b->C2Addr, b->sectorSize * 4);
            return 1;
        }
        if (info->sectorNum == -1 && info->transferMode == 2 && info->blockNum == 1) {
            b0 = &info->block[0];
            if (b0->C1ErrNum == 0) {
                c2 = (s32 *)b0->C2Addr;
                if (c2[0] | c2[1] | c2[2] | c2[3]) {
                    b0->errStatus = 0x17;
                    __osLeoAbnormalResume();
                    return 1;
                }
            }
            b0->errStatus = 0;
            __osLeoResume();
        }
        info->sectorNum++;
        if (stat & 0x40000000) {
            if (info->sectorNum > 0x54) {
                b->errStatus = 0x18;
                __osLeoAbnormalResume();
                return 1;
            }
            func_800932E0(D_800B5AF8, 0, 0x05000400, b->dramAddr, b->sectorSize);
            b->errStatus = 0;
            return 1;
        }
        if (info->sectorNum < 0x55) {
            b->errStatus = 0x18;
            __osLeoAbnormalResume();
            return 1;
        }
        return 1;
    }
    b->errStatus = 4; 
    __osLeoAbnormalResume();
    return 1;
}
