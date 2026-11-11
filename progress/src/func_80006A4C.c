/* Writes colour data for one entry of the vertex pool at pool+0x70 (16-byte records,
 * selected by `index`). Three 4-byte groups go in at +0xC, +0x1C and +0x2C: each holds
 * three colour components followed by the shared alpha `alpha` (arg11) at the group's
 * fourth byte. */
void func_80006A4C(void *pool, s32 index, s8 r0, s8 g0, u8 b0, u8 r1, u8 g1, u8 b1, u8 r2, u8 g2, u8 b2, u8 alpha) {
    s32 temp_a1;

    temp_a1 = (index & 0xFFFF) * 0x10;
    *(s8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0xC) = r0;
    *(s8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0xD) = g0;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0xE) = b0;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0xF) = alpha;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x1C) = r1;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x1D) = g1;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x1E) = b1;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x1F) = alpha;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x2C) = r2;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x2D) = g2;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x2E) = b2;
    *(u8 *)((temp_a1 + *(s32 *)((s8 *)pool + 0x70)) + 0x2F) = alpha;
}
