void slotSetSelected(s32 slot, s32 selected_index);
extern u8 stream_state[];

/* Toggles flag 0x4000 in the u16 at +0x2C of the object at stream_state+0x32F2,
 * then sets slot 0x1E's selection to 1 if the flag was just turned on, else 0. */
s32 toggle_sel_flag(void) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C);
    selected = 0;
    if (flags & 0x4000) {
        *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C) = (u16) (flags & 0xBFFF);
    } else {
        *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C) = (u16) (flags | 0x4000);
        selected = 1;
    }
    slotSetSelected(0x1E, selected);
    return 0;
}
