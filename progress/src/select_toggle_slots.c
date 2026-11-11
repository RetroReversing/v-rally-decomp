extern u8 gStreamState[];
s32 slot_set_selected(s32, u16);

/* Flips the selected flag of the first slot in the select table (stride 0x28, four
 * slots), copies the new value to the other three, then reports it to slot_set_selected. */
s32 select_toggle_slots(void) {
    u8 *table;
    u8 *base;
    u8 i;
    u32 off;

    table = *(u8 **)(gStreamState + 0x32F2);
    *(u16 *)(table + 0x50) = 1 - *(u16 *)(table + 0x50);
    base = table;
    i = 1;
    do {
        off = i * 0x28;
        *(u16 *)(off + base + 0x50) = *(u16 *)(base + 0x50);
        i++;
    } while (i < 4);
    slot_set_selected(0x11, *(u16 *)(*(u8 **)(gStreamState + 0x32F2) + 0x50));
    return 0;
}
