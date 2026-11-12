extern char stream_state[];
s32 slotSetSelected(s32 a, s32 b);

/* Reads the flags word at +0x2A of the current stream slot. Bit 0x4000 clears
 * and selects 2, bit 0x2000 clears and selects 1, bit 0x1000 clears alone; the
 * chosen value is passed to slotSetSelected for slot 0x1B. */
s32 func_8005FFE0(void) {
    s32 selected;
    u16 flags;

    flags = *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2A);
    selected = 0;
    if (flags & 0x4000) {
        *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2A) = (u16) (flags & 0xBFFF);
        selected = 2;
    } else if (flags & 0x2000) {
        *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2A) = (u16) (flags & 0xDFFF);
        selected = 1;
    } else if (flags & 0x1000) {
        *(u16 *)(*(void **)(stream_state + 0x32F2) + 0x2A) = (u16) (flags & 0xEFFF);
    }
    slotSetSelected(0x1B, selected);
    return 0;
}
