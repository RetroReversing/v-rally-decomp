extern u8 D_800A167C[];

/* Decrements the byte counter D_800A167C[index] unless it is already zero. Returns 0. */
s32 func_80068C78(s32 unused, s32 index) {
    u8 count;

    count = *(D_800A167C + index);
    if (count != 0) {
        *(D_800A167C + index) = count - 1;
    }
    return 0;
}
