/* Fills one 16-byte entry of the table at obj+0x70, for entry index idx: the x and y
   s16 values at +0 and +2, and the low halves of the six values after them at
   +0x10, +0x12, +0x20, +0x22, +0x30 and +0x32. */
void func_80007538(void *obj, s32 idx, s16 x, s16 y, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9)
{
    u32 off;

    off = (u16)idx * 16;
    *(s16 *)(off + *(u32 *)((u8 *)obj + 0x70)) = x;
    *(s16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 2) = y;
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x10) = ((u16 *)&a4)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x12) = ((u16 *)&a5)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x20) = ((u16 *)&a6)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x22) = ((u16 *)&a7)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x30) = ((u16 *)&a8)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x32) = ((u16 *)&a9)[1];
}
