extern char gStreamState[];
s32 slot_set_selected(s32, s32);

/* Toggles bit 0x8 in the flags (+0x2C) of the object at gStreamState+0x32F2, then
 * reports the new state (1 when the bit was set) to slot 0x19. */
s32 func_8005FE80(void) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C);
    selected = 0;
    if (flags & 8) {
        *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C) = (u16)(flags & 0xFFF7);
    } else {
        *(u16 *)(*(char **)(gStreamState + 0x32F2) + 0x2C) = (u16)(flags | 8);
        selected = 1;
    }
    slot_set_selected(0x19, selected);
    return 0;
}
