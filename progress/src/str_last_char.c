void debug_port_send();

/* Passes the string on through debug_port_send, then returns its last character (0 if the
 * string is empty). */
s8 str_last_char(s8 *str) {
    s32 prev;
    s32 last;
    s8 *p;
    u8 cur;

    p = str;
    debug_port_send();
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
