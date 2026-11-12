/* Returns the 2D dot product of the x/z s16 pairs (offsets 0 and 4) of vectors a and b. */
s32 func_8002E9E8(void *a, void *b) {
    return (*(s16 *)((s8 *)a + 0) * *(s16 *)((s8 *)b + 0)) + (*(s16 *)((s8 *)a + 4) * *(s16 *)((s8 *)b + 4));
}
