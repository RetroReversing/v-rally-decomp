s32 slotSetSelected(s32, s32);
s32 select_stream_char(u8, u8, u8);
extern u8 *gSelectState;
extern char stream_state[];

/* Advances the stream slot for the current select entry (slots are 0x28 bytes, starting at +0x44)
 * by one step, up to a maximum of 2, and marks it selected. Always returns 1. */
s32 stream_slot_advance(s32 arg0) {
    u8 *stream;
    u8 *slot;
    u8 *slot_b;
    u8 step;
    u8 next_step;

    stream = *(u8 **)(stream_state + 0x32F2);
    slot = stream + ((*(u8 *)(stream + *(s8 *)(gSelectState + 0x228) + 0x32) * 0x28) + 0x44);
    slot_b = slot + (select_stream_char(stream[0x1F], stream[0x21], stream[0x23]) & 0xFF);
    step = slot_b[0x18];
    if (step < 2U) {
        next_step = step + 1;
        slot_b[0x18] = next_step;
        slotSetSelected(arg0, next_step & 0xFF);
    }
    return 1;
}
