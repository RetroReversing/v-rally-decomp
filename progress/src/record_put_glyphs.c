extern u8 stream_state[];
void func_8006BE50(u8 *p, u8 a);

/* Sends a glyph record to the stream buffer picked by bank (labels follow jtbl_800A5808): banks
 * 0-5 index the per-bank pointer table at row and col, 22-26 use fixed buffers; other banks are
 * ignored. */
void record_put_glyphs(s32 kind, s32 bank, s32 row, s32 col) { u8 a=(u8)kind, b=(u8)bank, c=(u8)row, d=(u8)col;
    switch (b) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        func_8006BE50(((u8 **)((u8 *)stream_state + 0x10386))[b] + c * 708 + ((d << 6) + 0x2C), a);
        break;
    case 22:
        func_8006BE50((u8 *)stream_state + 0x34A2 + (d << 6), a);
        break;
    case 23:
        func_8006BE50((u8 *)stream_state + 0x33A2 + (d << 6), a);
        break;
    case 24:
        func_8006BE50((u8 *)stream_state + 0x37A2, a);
        break;
    case 25:
        func_8006BE50((u8 *)stream_state + 0x37E2, a);
        break;
    case 26:
        func_8006BE50((u8 *)stream_state + 0x3822, a);
        break;
    case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
    case 17: case 18: case 19: case 20: case 21:
        break;
    }
}
