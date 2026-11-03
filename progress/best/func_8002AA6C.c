extern char *D_8009CEE0[];
extern u8 D_8009CEE8;

s32 func_8002AA6C(char *src, char *end)
{
    char *look;
    char *lim;
    char buf[0x11];
    char *out;
    char *p;
    char *q;
    s32 c;
    s32 i;
    s32 off;

    look = src + 1;
    out = buf;
    lim = buf + 0x11;
    for (;;) {
        c = *src;
        if ((c == 0x20) || (c == 9)) {
            *out = 0;
            goto done;
        }
        if ((c == 0x2C) || (c == 0xD)) {
            *out = 0;
            goto done;
        }
        if (c == 0x23) {
            *out = 0;
            goto done;
        }
        if (c == 0x2F) {
            if ((look < end) && (*look == c)) {
                *out = 0;
                goto done;
            }
        }
        if (src >= end) {
            *out = 0;
            goto done;
        }
        look++;
        *out = *src;
        out++;
        src++;
        if ((s32)out < (s32)lim) {
            continue;
        }
        goto done;
    }
done:
    i = 0;
    if (D_8009CEE8 != 0xFF) {
        off = 0;
        do {
            p = buf;
            q = *(char **)((char *)D_8009CEE0 + off);
            while (*p == *q && *p != 0 && *q != 0) {
                p++;
                q++;
            }
            if (*p == 0 && *q == 0) {
                return i + 1;
            }
            off += 12;
            i++;
        } while (*((u8 *)&D_8009CEE8 + off) != 0xFF);
    }
    return 0;
}
