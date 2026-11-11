s32 ctype_toupper(u8);

/* Compares at most `count` characters of two strings, ignoring case. Returns the
 * difference of the first pair that differs, or 0 when the strings match up to the
 * count or a NUL. */
s32 str_ncasecmp(u8 *s1, u8 *s2, s32 count) {
    u8 *p2 = s2;
    unsigned short zero;
    s32 n = count - 1;
    s32 first;
    s32 second;
    s32 d;
    u8 c1;
    u8 c2;
    char pad[8];

    if (count != 0) {
        do {
            c1 = *s1;
            c2 = *p2;
            first = ctype_toupper(c1);
            second = ctype_toupper(c2);
            d = first - second;
            if ((d != 0) || (c1 == 0)) return d;
            s1++;
            n--;
            p2++;
        } while (n != -1);
    }
    zero = 0;
    return zero;
}
