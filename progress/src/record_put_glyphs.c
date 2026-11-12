extern u8 stream_state[];
void func_8006BE50(u8 *p, u8 a);

/* Sends a glyph record to the stream buffer picked by bank, at the row and col
 * position; kinds 0 and 1 also save the slot state first. Other kinds are ignored. */
void record_put_glyphs(s32 kind, s32 bank, s32 row, s32 col) { u8 a=(u8)kind, b=(u8)bank, c=(u8)row, d=(u8)col;
    switch (b) {
    case 0:
        func_8006BE50(((u8 **)((u8 *)stream_state + 0x10386))[b] + c * 708 + ((d << 6) + 0x2C), a);
        break;
    case 1:
        func_8006BE50((u8 *)stream_state + 0x34A2 + (d << 6), a);
        break;
    case 2:
        func_8006BE50((u8 *)stream_state + 0x33A2 + (d << 6), a);
        break;
    case 3:
        func_8006BE50((u8 *)stream_state + 0x37A2, a);
        break;
    case 4:
        func_8006BE50((u8 *)stream_state + 0x37E2, a);
        break;
    case 5:
        func_8006BE50((u8 *)stream_state + 0x3822, a);
        break;
    case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
    case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24: case 25: case 26:
        break;
    }
}
