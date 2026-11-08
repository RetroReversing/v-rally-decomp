typedef struct {
    s32 status;
    void *queue;
    s32 channel;
    u8 id[32];
    u8 label[32];
    s32 version;
    s32 dir_size;
    s32 inode_table;
    s32 minode_table;
    s32 dir_table;
    s32 inode_start_page;
    u8 banks;
    u8 activebank;
} OSPfsX;

s32 __osPfsSelectBank(OSPfsX *, u8);
u32 __osContRamRead(void *, s32, u16, u8 *);
u32 __osContRamWrite(void *, s32, u16, u8 *, s32);
void func_80091600(void *, void *, s32);
extern s32 D_800A3B30;
extern u8 D_800A3B34;
extern u8 D_800C02AE[];

static __inline__ u16 sumcalc(u8 *ptr, int len)
{
    int i;
    u32 sum = 0;
    u8 *tmp = ptr;
    for (i = 0; i < len; i++) {
        sum += *tmp;
        tmp++;
    }
    return sum & 0xFFFF;
}

s32 __osPfsRWInode(OSPfsX *pfs, u8 *inode, u8 flag, u8 bank)
{
    int j;
    s32 ret;
    u8 sum;
    u8 *addr;
    int offset;

    if (flag == 0 && bank == D_800A3B34 && pfs->channel == D_800A3B30) {
        func_80091600(D_800C02AE + 0x7062, inode, 0x100);
        return 0;
    }
    if (pfs->activebank != 0) {
        ret = __osPfsSelectBank(pfs, 0);
        if (ret != 0) {
            return ret;
        }
    }
    offset = (bank > 0) ? 1 : pfs->inode_start_page;
    if (flag == 1) {
        inode[1] = sumcalc(inode + offset * 2, (128 - offset) * 2);
    }
    for (j = 0; j < 8; j++) {
        addr = inode + j * 32;
        if (flag == 1) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == 0) {
        sum = sumcalc(inode + offset * 2, (128 - offset) * 2);
        if (sum != inode[1]) {
            for (j = 0; j < 8; j++) {
                addr = inode + j * 32;
                ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr);
            }
            sum = sumcalc(inode + offset * 2, (128 - offset) * 2);
            if (sum != inode[1]) {
                return 3;
            }
            for (j = 0; j < 8; j++) {
                addr = inode + j * 32;
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            }
        }
    }
    D_800A3B34 = bank;
    func_80091600(inode, D_800C02AE + 0x7062, 0x100);
    D_800A3B30 = pfs->channel;
    return 0;
}
