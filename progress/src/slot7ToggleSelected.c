void slot_set_selected(s32, s32);
extern u8 gOrderState[];

/* Toggles the selected flag of order slot 7 (byte at gOrderState+0x7FC8) and passes the new value to slot_set_selected. Returns 0. */
s32 slot7ToggleSelected(void) {
    s32 selected;

    if (gOrderState[0x7FC8] == 0) {
        gOrderState[0x7FC8] = 1;
        selected = 1;
    } else {
        gOrderState[0x7FC8] = 0;
        selected = 0;
    }
    slot_set_selected(7, selected);
    return 0;
}
