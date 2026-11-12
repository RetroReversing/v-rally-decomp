s32 slotSetSelected(s32, s32);
extern char stream_state[];

/* Toggles bit 0 (selected) of the record at stream_state+0x32F2 (flags are at offset 9), then
   reports the new state to slot arg0. Returns 0. */
s32 func_8005F188(s32 slot)
{
    u16 *record;
    u16 flags;

    record = *(u16 **)(stream_state + 0x32F2);
    flags = record[9];
    record[9] = (flags & 1) ? (flags & 0xFFFE) : (flags | 1);
    slotSetSelected(slot, (*(u16 **)(stream_state + 0x32F2))[9] & 1);
    return 0;
}
