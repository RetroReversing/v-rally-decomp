extern u8 stream_state[];
s32 slotSetSelected();

/* Advances the mode byte at +0x30 of the state block (0 stays 0; 1..9 wrap to 0 after 9)
 * and passes the new mode to slotSetSelected. */
s32 func_80062C48(s32 slot) {
    u8 mode;

    mode = *(u8 *)(*(char **)(stream_state + 0x32F2) + 0x30);
    if (mode != 0) {
        if (mode < 9) {
            *(u8 *)(*(char **)(stream_state + 0x32F2) + 0x30) = mode + 1;
        } else {
            *(u8 *)(*(char **)(stream_state + 0x32F2) + 0x30) = 0;
        }
    }
    slotSetSelected(slot, *(u8 *)(*(char **)(stream_state + 0x32F2) + 0x30));
    return 0;
}
