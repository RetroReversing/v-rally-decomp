/* Cosine of a 16-bit angle (0x10000 = full turn): sin of the angle advanced by a quarter turn. */
extern s16 sins(s32);

s16 coss(s32 angle) {
    return sins((angle + 0x4000) & 0xFFFF);
}
