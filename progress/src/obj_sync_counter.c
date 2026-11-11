extern u8 D_800A73E0[];

/* Syncs obj's counter (+0x7A) with the entry at obj->+0xA8->+0x24. If the entry's
 * value + 1 is within the limit byte at D_800A73E0+0x6C00, clears bit 2 of +0x80 and
 * copies the value into +0x7A (zeroed when it is 10 or more). Otherwise sets bit 2. */
void obj_sync_counter(void *obj)
{
    s32 value;
    u32 next;
    void *entry;

    entry = *(void **)((u8 *)*(void **)((u8 *)obj + 0xA8) + 0x24);
    if (entry != NULL) {
        next = **(s32 **)((u8 *)entry + 0x70) + 1;
        if (((u8)D_800A73E0[0x6C00] >= next) && (next != D_800A73E0[0x6C00])) {
            *(s32 *)((u8 *)obj + 0x80) &= ~4;
            value = **(s32 **)((u8 *)entry + 0x70);
            *(s16 *)((u8 *)obj + 0x7A) = (s16)value;
            if ((s16)value >= 0xA) {
                *(s16 *)((u8 *)obj + 0x7A) = 0;
            }
            return;
        }
        *(s32 *)((u8 *)obj + 0x80) |= 4;
    }
}
