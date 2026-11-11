void *select_get_entry(u32);
s32 func_8005937C();
s32 func_8006185C();
s32 func_80069A08();
s32 UpdateSelectedEntry();
s32 func_8007A7D0();
extern void *gSelectState;
extern char gStreamState[];

/* Refreshes the select state from the current stream entry: in mode 0 it takes the
   entry's range and the selected record's flag, otherwise it runs the alternate
   handler, then passes the state's flag to func_8007A7D0. */
void func_8007A9A8(void)
{
    void *stream;
    u8 *entry;
    u8 *entry2;
    u8 *records;
    void *rec;
    s32 mode;
    void *sel;

    stream = *(void **)(gStreamState + 0x325A);
    entry = *(u8 **)((u8 *)stream + 0x10) + *(s16 *)((u8 *)stream + 2) * 0x14;
    sel = gSelectState;
    mode = *((u8 *)sel + 0x245);
    if (mode == 0) {
        *((u8 *)gSelectState + 0x238) = entry[0xE] - entry[0xD];
        func_8005937C(entry[0xE], *((u8 *)gSelectState + *((u8 *)gSelectState + 0x238) + 0x23D), sel);
        records = *(u8 **)(gStreamState + 0x32F2);
        entry2 = records + *(u8 *)(records + *(s8 *)((u8 *)gSelectState + 0x228) + 0x32) * 0x28;
        rec = gSelectState;
        *((u8 *)rec + 0x237) = *(u16 *)(entry2 + 0x4E);
        func_80069A08(entry2, rec);
    } else {
        UpdateSelectedEntry(mode, entry, gSelectState);
        func_80069A08();
        func_8006185C((s32)select_get_entry(*((u8 *)gSelectState + 0x238)), 1);
    }
    func_8007A7D0(*((u8 *)gSelectState + 0x237));
}
