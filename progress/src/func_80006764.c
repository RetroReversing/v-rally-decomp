/* Writes one 16-byte record of the table at obj+0x70 (index is the record number):
 * x and y at +0 and +2, then the low halfword of each of the four 32-bit values
 * at +0x10, +0x12, +0x20 and +0x22. */
void func_80006764(void *obj, s32 index, s16 x, s16 y, s32 v0, s32 v1, s32 v2, s32 v3)
{
    u32 off;

    off = (u16)index * 16;
#ifdef PORT
    *(s16 *)(off + *(u8 **)((u8 *)obj + 0x70)) = x;
    *(s16 *)(off + *(u8 **)((u8 *)obj + 0x70) + 2) = y;
    *(u16 *)(off + *(u8 **)((u8 *)obj + 0x70) + 0x10) = ((u16 *)&v0)[1];
    *(u16 *)(off + *(u8 **)((u8 *)obj + 0x70) + 0x12) = ((u16 *)&v1)[1];
    *(u16 *)(off + *(u8 **)((u8 *)obj + 0x70) + 0x20) = ((u16 *)&v2)[1];
    *(u16 *)(off + *(u8 **)((u8 *)obj + 0x70) + 0x22) = ((u16 *)&v3)[1];
#else
    *(s16 *)(off + *(u32 *)((u8 *)obj + 0x70)) = x;
    *(s16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 2) = y;
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x10) = ((u16 *)&v0)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x12) = ((u16 *)&v1)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x20) = ((u16 *)&v2)[1];
    *(u16 *)(off + *(u32 *)((u8 *)obj + 0x70) + 0x22) = ((u16 *)&v3)[1];
#endif
}
