s32 stream_refresh_car_flags();
s32 slotSetSelected();
extern char stream_state[];

/* Scans the car-select mask byte (sel[0x2F], bits 0..3) for the first clear bit.
   The bit just below it is cleared; if all four are set, bit 3 is cleared.
   Then refreshes the car flags and marks slot 0x1C as selected. */
s32 stream_update_car_mask(void) {
    s32 i;
    s32 idx;
    s32 one;
    s32 last;
    s32 clear_mask;
    u8 mask;
    u8 *sel;

    i = 0;
    one = 1;
    last = 3;
    clear_mask = -9;
loop_1:
    sel = *(u8 **)(stream_state + 0x32F2);
    mask = sel[0x2F];
    idx = i & 0xFF;
    if (((mask >> idx) & 1) != 0) {
        goto block_4;
    }
    if (idx == 0) {
        goto block_9;
    }
    i -= 1;
    sel[0x2F] = mask & ~(one << i);
    goto block_9;
block_4:
    if (idx == last) {
        sel[0x2F] = mask & clear_mask;
        goto block_9;
    }
    i += 1;
    if ((u32) (i & 0xFF) < 4U) {
        goto loop_1;
    }
block_9:
    stream_refresh_car_flags(mask, sel, last, clear_mask);
    slotSetSelected(0x1C, i & 0xFF);
    return 0;
}
