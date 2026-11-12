/* Writes the x and z components (offsets 0 and 4) of minuend - subtrahend into dst as signed 16-bit values. The y component is not touched. */
void vec_diff_xz(void *dst, void *subtrahend, void *minuend) {
    *(s16 *)((s8 *)dst + 0) = (s16)(*(u16 *)((s8 *)minuend + 0) - *(u16 *)((s8 *)subtrahend + 0));
    *(s16 *)((s8 *)dst + 4) = (s16)(*(u16 *)((s8 *)minuend + 4) - *(u16 *)((s8 *)subtrahend + 4));
}
