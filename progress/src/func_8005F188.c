s32 slot_set_selected(s32, s32);
extern char gStreamState[];

/* Toggles bit 0 (selected) of the record at gStreamState+0x32F2 (flags are at offset 9), then
   reports the new state to slot arg0. Returns 0. */
s32 func_8005F188(s32 slot)
{
    u16 *record;
    u16 flags;

    record = *(u16 **)(gStreamState + 0x32F2);
    flags = record[9];
    record[9] = (flags & 1) ? (flags & 0xFFFE) : (flags | 1);
    slot_set_selected(slot, (*(u16 **)(gStreamState + 0x32F2))[9] & 1);
    return 0;
}
