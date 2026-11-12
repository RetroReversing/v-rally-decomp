extern char stream_state[];

/* Searches the four 14-byte name entries for the initials at query[6..8]. Each letter is
 * a 5-bit value stored as 'A' + n. Returns the matching entry index, or 5 when nothing
 * matches or the search flag query[0xC] is clear. */
s32 func_8006B924(u8 *query) {
    s8 letters[3];
    u8 i;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 off;

    if (query[0xC] != 0) {
        for (i = 0; i < 4; i++) {
            off = i * 14;
            c0 = ((*(u16 *)(stream_state + 0x6E26 + off) >> 10) & 0x1F) + 0x41;
            letters[0] = c0;
            c1 = ((*(u16 *)(stream_state + 0x6E26 + off) >> 5) & 0x1F) + 0x41;
            letters[1] = c1;
            c2 = (stream_state[0x6E27 + off] & 0x1F) + 0x41;
            letters[2] = c2;
            if (c0 == query[6] && c1 == query[7] && c2 == query[8]) {
                return i;
            }
        }
    }
    return 5;
}
