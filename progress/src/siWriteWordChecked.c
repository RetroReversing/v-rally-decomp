extern char D_800A6FA0[];
extern char D_800A6FA4[];
void func_800914E0(void *, void *, s32);
s32 si_busy();

/* Writes `value` to the uncached address `addr` (SI/PIF space). Reports a misaligned address first, then fails with -1 while SI is busy. */
s32 siWriteWordChecked(s32 addr, s32 value) {
    if (addr & 3) {
        func_800914E0(D_800A6FA0, D_800A6FA4, 0x34);
    }
    if (si_busy() != 0) {
        return -1;
    }
    *(s32 *)(addr | 0xA0000000) = value;
    return 0;
}
