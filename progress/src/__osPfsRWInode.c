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
void __osCopyBytes(void *, void *, s32);
extern s32 D_800A3B30;
extern u8 D_800A3B34;
extern u8 gStreamState[];

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

/* Reads (flag 0) or writes (flag 1) one 256-byte inode block of a controller-pak
 * file system bank. The inode checksum lives in inode[1] and covers the bytes after
 * the start page. On a read, a checksum mismatch falls back to the mirror copy and
 * then fails with 3 if that is also bad. The last bank and channel are cached so
 * a repeat read of the same block is served from the buffer. */
s32 __osPfsRWInode(OSPfsX *pfs, u8 *inode, u8 flag, u8 bank)
{
    int i;
    s32 ret;
    u8 sum;
    u8 *addr;
    int offset;

    if (flag == 0 && bank == D_800A3B34 && pfs->channel == D_800A3B30) {
        __osCopyBytes(gStreamState + 0x7062, inode, 0x100);
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
    for (i = 0; i < 8; i++) {
        addr = inode + i * 32;
        if (flag == 1) {
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + i, addr, 0);
            ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + i, addr, 0);
        } else {
            ret = __osContRamRead(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + i, addr);
        }
        if (ret != 0) {
            return ret;
        }
    }
    if (flag == 0) {
        sum = sumcalc(inode + offset * 2, (128 - offset) * 2);
        if (sum != inode[1]) {
            for (i = 0; i < 8; i++) {
                addr = inode + i * 32;
                ret = __osContRamRead(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + i, addr);
            }
            sum = sumcalc(inode + offset * 2, (128 - offset) * 2);
            if (sum != inode[1]) {
                return 3;
            }
            for (i = 0; i < 8; i++) {
                addr = inode + i * 32;
                ret = __osContRamWrite(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + i, addr, 0);
            }
        }
    }
    D_800A3B34 = bank;
    __osCopyBytes(inode, gStreamState + 0x7062, 0x100);
    D_800A3B30 = pfs->channel;
    return 0;
}
