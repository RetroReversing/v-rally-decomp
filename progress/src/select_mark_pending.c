extern u8 *gRecords;
extern void *gLeague;
extern u8 *gSelectState;
void *select_get_entry(u32);
void slot_set_selected();
void func_80068D9C();
void func_8008A0D8();

/* Marks the selected record (0x28 bytes each, index at gSelectState+0x22A) as pending by
 * setting its 0x10 flag. If the flag was already set, hands over to func_80068D9C.
 * Otherwise sends event 0x17, writes three 0x50 bytes into select entry 6 and selects the
 * slot. Returns 0. */
s32 select_mark_pending(s32 slot) {
    u8 *rec;
    u8 flags;
    u8 *entry;

    rec = gRecords + (*(s8 *)(gSelectState + 0x22A)) * 0x28;
    flags = rec[0x48];
    if (flags & 0x10) {
        func_80068D9C(slot);
        return 0;
    }
    rec[0x48] = flags | 0x10;
    func_8008A0D8(gLeague, 0x17, 0);
    entry = select_get_entry(6);
    entry[0xF] = 0x50;
    entry[0x10] = 0x50;
    entry[0x11] = 0x50;
    slot_set_selected(slot, 1);
    return 0;
}
