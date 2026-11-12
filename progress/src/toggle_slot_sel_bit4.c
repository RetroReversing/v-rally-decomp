void slotSetSelected(s32 slot, s32 selected_index);
extern u8 stream_state[];

/* Toggles flag 4 in the u16 at +0x2C of the object at stream_state+0x32F2, then
 * sets the selection of `slot` to 1 if the flag was just turned on, else 0. */
s32 toggle_slot_sel_bit4(s32 slot) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C);
    if (flags & 4) {
        *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C) = (u16) (flags & 0xFFFB);
        selected = 0;
    } else {
        *(u16 *)(*(u8 **)(stream_state + 0x32F2) + 0x2C) = (u16) (flags | 4);
        selected = 1;
    }
    slotSetSelected(slot, selected);
    return 0;
}
