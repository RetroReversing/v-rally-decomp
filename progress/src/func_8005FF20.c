extern char gStreamState[];
s32 slot_set_selected(s32, s32);

/* Toggles bit 0x100 in the flags (+0x2C) of the object at gStreamState+0x32F2, then
 * reports the new state (1 when the bit was set) to slot 0x1A. */
s32 func_8005FF20(void) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C);
    selected = 0;
    if (flags & 0x100) {
        *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C) = (u16)(flags & 0xFEFF);
    } else {
        *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C) = (u16)(flags | 0x100);
        selected = 1;
    }
    slot_set_selected(0x1A, selected);
    return 0;
}
