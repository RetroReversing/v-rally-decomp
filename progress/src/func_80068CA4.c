extern char D_800A167C[];

/* Bumps the byte counter D_800A167C[idx] by one, saturating at 8. */
s32 func_80068CA4(s32 unused, s32 idx) {
    u8 count;

    count = *(D_800A167C + idx);
    if (count < 8U) {
        *(D_800A167C + idx) = count + 1;
    }
    return 0;
}
