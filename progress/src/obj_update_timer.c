/* Per-frame update for obj. If the entry at obj->+0xA8->+0x24 has both bits 7 and 8 of
 * its word at +0x14 set, bit 2 of obj's flags (+0x80) is cleared and obj's counter (+0x7A)
 * is set to the entry's sub-object value + 1. Otherwise the flag is set. Then the
 * negated half of a table entry's u16 at +6 is stored in obj's word at +0x70. */
void obj_update_timer(void *obj)
{
    u8 *entry;
    u8 *table;
    s32 n;
    s32 offset;

    table = (u8 *)0x180;
    entry = *((u8 **)((*((u8 **)(((u8 *)obj) + 0xA8))) + 0x24));
    if (entry != NULL)
    {
        *((vs32 *)(((u8 *)obj) + 0x80)) |= 4;
        if (((*((s32 *)(entry + 0x14))) & 0x180) == (s32)table)
        {
            table = *((u8 **)(entry + 0x6C));
            n = *((s32 *)(table + 8));
            *((vs32 *)(((u8 *)obj) + 0x80)) &= ~4;
            *((s16 *)(((u8 *)obj) + 0x7A)) = n + 1;
        }
        table = *((u8 **)((*((u8 **)(((u8 *)obj) + 0xA4))) + 4));
        offset = (*((s16 *)(((u8 *)obj) + 0x7A))) * 4;
        *((s16 *)(((u8 *)obj) + 0x70)) = -((*((u16 *)((*((u8 **)((s32)offset + (s32)table))) + 6))) >> 1);
    }
}
