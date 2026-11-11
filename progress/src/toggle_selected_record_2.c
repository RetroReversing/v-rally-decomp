extern int gRecords;
s32 slot_set_selected();
extern void *gSelectState;
extern char gStreamState[];

/* Toggles bit 2 of the flags byte (+0x48) of the currently selected record (0x28
 * bytes each, index at gSelectState+0x22A), then sets slot 0x1E to that bit. */
s32 toggle_selected_record_2(void)
{
    u8 flags;
    u8 new_flags;
    void *record;
    u8 *flags_ptr;

    record = gRecords + ((*((s8 *)(((char *)gSelectState) + 0x22A))) * 0x28);
    flags = *((u8 *)(((char *)record) + 0x48));
    if (flags & 4) {
        new_flags = flags & 0xFB;
    } else {
        new_flags = flags | 4;
    }
    *((u8 *)(((char *)record) + 0x48)) = new_flags;
    flags_ptr = &(*((u8 *)(((char *)(gRecords + ((*((s8 *)(((char *)gSelectState) + 0x22A))) * 0x28))) + 0x48)));
    slot_set_selected(0x1E, (((u8)(*flags_ptr)) >> 2) & 1);
    return 0;
}
