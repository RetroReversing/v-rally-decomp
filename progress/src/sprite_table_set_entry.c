/* Writes one 16-byte entry into the table at obj->+0x70, at slot 'index'. The
 * first two fields are x and y. The other fields are the high halves of the
 * trailing arguments (the u16 at byte offset 2 of each). */
void sprite_table_set_entry(void *obj, s32 index, s16 x, s16 y, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10)
{
    *(s16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10)) = x;
    *(s16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 2) = y;
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 4) = ((u16 *)&a4)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x10) = ((u16 *)&a5)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x12) = ((u16 *)&a6)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x14) = ((u16 *)&a7)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x20) = ((u16 *)&a8)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x22) = ((u16 *)&a9)[1];
    *(u16 *)(*(u8 **)((u8 *)obj + 0x70) + ((index & 0xFFFF) * 0x10) + 0x24) = ((u16 *)&a10)[1];
}
