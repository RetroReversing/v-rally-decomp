s32 osVirtualToPhysical();
s32 func_800914E0();
s32 sp_status_busy();
extern char D_800A722C[];
extern char D_800A7230[];

/* Starts an RSP DMA between RSP memory (mem_addr) and RDRAM (dram_addr). Both
 * addresses must be 8-byte aligned and len is the byte count less one. The
 * direction is RDRAM to RSP when from_rdram is nonzero. Returns -1 without
 * starting anything if a DMA is already busy. */
s32 sp_dma_start(s32 from_rdram, s32 mem_addr, s32 dram_addr, s32 len) {
    if (mem_addr & 7) {
        func_800914E0(D_800A722C, D_800A7230, 0x3A);
    }
    if (dram_addr & 7) {
        func_800914E0(D_800A722C, D_800A7230, 0x3B);
    }
    if (len & 7) {
        func_800914E0(D_800A722C, D_800A7230, 0x3C);
    }
    if (sp_status_busy() != 0) {
        return -1;
    }
    *(vs32 *)0xA4040000 = mem_addr;
    *(vs32 *)0xA4040004 = osVirtualToPhysical(dram_addr);
    if (from_rdram == 0) {
        *(vs32 *)0xA404000C = len - 1;
    } else {
        *(vs32 *)0xA4040008 = len - 1;
    }
    return 0;
}
