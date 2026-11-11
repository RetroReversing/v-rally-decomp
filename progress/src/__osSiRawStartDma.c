#define SI_DRAM_ADDR (*(vu32 *)0xA4800000)
#define SI_PIF_ADDR_RD64B (*(vu32 *)0xA4800004)
#define SI_PIF_ADDR_WR64B (*(vu32 *)0xA4800010)
#define SI_STATUS (*(vu32 *)0xA4800018)
#define PIF_RAM_PHYS 0x1FC007C0

s32 osVirtualToPhysical(void *);
void osWritebackDCache(void *, s32);
void osInvalDCache(void *, s32);

/* Starts an SI DMA of 64 bytes between buf and PIF RAM. dir 1 writes buf back to memory
 * first and sends it to the PIF; dir 0 reads PIF RAM into buf and invalidates the cache
 * after. Returns -1 if the SI is busy, otherwise 0. */
s32 __osSiRawStartDma(s32 dir, void *buf) {
    if (SI_STATUS & 3) {
        return -1;
    }
    if (dir == 1) {
        osWritebackDCache(buf, 0x40);
    }
    SI_DRAM_ADDR = osVirtualToPhysical(buf);
    if (dir == 0) {
        SI_PIF_ADDR_RD64B = PIF_RAM_PHYS;
    } else {
        SI_PIF_ADDR_WR64B = PIF_RAM_PHYS;
    }
    if (dir == 0) {
        osInvalDCache(buf, 0x40);
    }
    return 0;
}
