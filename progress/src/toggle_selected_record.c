extern int gRecords;
s32 slot_set_selected();
extern void *gSelectState;
extern char gStreamState[];

/* Toggles bit 1 of the flags byte (+0x48) of the currently selected record (0x28
 * bytes each, index at gSelectState+0x22A), then sets slot 0x1D to that bit. */
s32 toggle_selected_record(void) {
    u8 flags;
    u8 new_flags;
    void *record;
    u8 *flags_ptr;

    record = gRecords + ((*((s8 *)(((char *)gSelectState) + 0x22A))) * 0x28);
    flags = *((u8 *)(((char *)record) + 0x48));
    if (flags & 2) {
        new_flags = flags & 0xFD;
    } else {
        new_flags = flags | 2;
    }
    *((u8 *)(((char *)record) + 0x48)) = new_flags;
    flags_ptr = &(*((u8 *)(((char *)(gRecords + ((*((s8 *)(((char *)gSelectState) + 0x22A))) * 0x28))) + 0x48)));
    slot_set_selected(0x1D, (((u8)(*flags_ptr)) >> 1) & 1);
    return 0;
}
