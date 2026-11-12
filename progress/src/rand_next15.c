extern s32 gRandSeed;

/* Linear congruential RNG step: advances gRandSeed and returns a 15-bit value. */
s32 rand_next15(void) {
    s32 temp_lo;

    temp_lo = gRandSeed * 0x41C64E6D;
    gRandSeed = temp_lo + 0x3039;
    return ((s32) (temp_lo + 0x303A) >> 0x10) & 0x7FFF;
}
