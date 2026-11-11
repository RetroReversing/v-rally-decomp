void func_8009A6C4();

/* Passes the string on through func_8009A6C4, then returns its last character (0 if the
 * string is empty). */
s8 str_last_char(s8 *str) {
    s32 prev;
    s32 last;
    s8 *p;
    u8 cur;

    p = str;
    func_8009A6C4();
    cur = (u8) *p;
    last = 0;
    if (*p != 0) {
        do {
            p += 1;
            prev = cur << 0x18;
            cur = (u8) *p;
            last = prev >> 0x18;
        } while (*p != 0);
    }
    return (s8) last;
}
