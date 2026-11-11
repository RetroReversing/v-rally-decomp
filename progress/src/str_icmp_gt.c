unsigned char toLowerChar();

/* Case-insensitive string comparison: returns 1 if str sorts after other, 0 if before, and
 * otherwise 1 when str is longer than other (its next char is non-zero), 0 when the same. */
s32 str_icmp_gt(u8 *str, u8 *other) {
    s32 i = 0;
    u8 *p, *q;
    if (*str == 0) goto finish;
    p = str;
    q = other;
    for (;;) {
        if (*q == 0) goto finish;
        if ((u8)toLowerChar(*p) > (u8)toLowerChar(*q)) return 1;
        if ((u8)toLowerChar(*p) < (u8)toLowerChar(*q)) return 0;
        p++; q++; i++;
        if (*p == 0) break;
    }
finish:
    return str[i] != 0;
}
