void slotSetSelected(s32, s32);
extern u8 stream_state[];

/* Toggles option flag at offset 0x38 in the stream state sub-struct, and updates slot 0x1D selection. */
s32 func_80060178(void) {
    u16 *state_ptr;
    u16 val;

    state_ptr = *(u16 **)&stream_state[0x32F2];
    val = 1 - state_ptr[0x38 / sizeof(u16)];
    state_ptr[0x38 / sizeof(u16)] = val;
    slotSetSelected(0x1D, val);
    return 0;
}
