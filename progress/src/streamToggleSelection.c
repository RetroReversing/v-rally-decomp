extern u8 stream_state[];

void slotSetSelected(s32 slot, s32 selectedIndex);

/* Flips the 0/1 selection flag at stream_state+0x32F2 (+0x1C) and applies the new value to slot 0x18. */
s32 streamToggleSelection(void) {
    u16 selected;

    selected = 1 - *((u16 *) (*((char **) (stream_state + 0x32F2)) + 0x1C));
    *((u16 *) (*((char **) (stream_state + 0x32F2)) + 0x1C)) = selected;
    slotSetSelected(0x18, selected & 0xFFFF);
    return 0;
}
