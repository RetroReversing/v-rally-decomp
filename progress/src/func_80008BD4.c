/* Writes six 16-bit coordinates (each value shifted left by 6, i.e. 10.6 fixed point) into
 * entry `index` of the record table at owner+0x70. Each 16-byte entry holds the fields at +0x8,
 * +0xA, +0x18, +0x1A, +0x28 and +0x2A. The last four values are read from the high halves of
 * the stack arguments. */
void func_80008BD4(void *owner, s32 index, s32 x0, s32 y0, s32 x1, s32 y1, s32 x2, s32 y2)
{
    s32 temp_a2;
    s32 temp_a3;

    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0x8) = (s16) ((temp_a2 = x0 & 0xFFFF) << 6);
    temp_a3 = y0 & 0xFFFF;
    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0xA) = (s16) (temp_a3 << 6);
    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0x18) = (s16) (((u16 *)&x1)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0x1A) = (s16) (((u16 *)&y1)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0x28) = (s16) (((u16 *)&x2)[1] << 6);
    *(s16 *)((char *)*(s32 *)((char *)owner + 0x70) + ((index & 0xFFFF) * 0x10) + 0x2A) = (s16) (((u16 *)&y2)[1] << 6);
}
