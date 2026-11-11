/* Writes four bytes into entry `index` of the 16-byte-entry table at obj+0x70. */
void setTableEntryBytes(void *obj, s32 index, s8 a, s8 b, u8 c, u8 d)
{
    s32 offset;

    offset = (index & 0xFFFF) * 0x10;
    *(s8 *)((s8 *)(offset + *(s32 *)((s8 *)obj + 0x70)) + 0xC) = a;
    *(s8 *)((s8 *)(offset + *(s32 *)((s8 *)obj + 0x70)) + 0xD) = b;
    *(u8 *)((s8 *)(offset + *(s32 *)((s8 *)obj + 0x70)) + 0xE) = c;
    *(u8 *)((s8 *)(offset + *(s32 *)((s8 *)obj + 0x70)) + 0xF) = d;
}
