extern void memcpy(void *, void *, s32);
extern u8 exp_char;
extern s8 gGameState[];

/* Formats a fixed-point value as "d.ddd<suffix><sign>dd" into dst: the first digit, a
   point, the remaining fraction digits, and a signed exponent. Trailing zeros and a
   bare point are dropped unless the global trim flag is clear. */
void func_80098A1C(u8 *digits, s32 digit_count, s32 exponent, s8 *dst)
{
    s32 length;
    s32 offset;
    s8 *out;
    u8 *src;
    u8 ch;
    length = digit_count - 1;
    offset = exponent;
    out = dst;
    src = digits;
    ch = *src;
    *out = ch;
    out++;
    *out = '.';
    out++;
    src++;
    memcpy(out, src, length);
    out += length;
    if (gGameState[0x6b24] == 0) {
        if (out[-1] == '0') {
            do { out--; } while (out[-1] == '0');
        }
        out -= (out[-1] == '.');
    }
    *out = exp_char;
    out++;
    if (offset < 0) { offset = -offset; *out = '-'; }
    else *out = '+';
    out++;
    if (offset >= 100) {
        *out++ = offset / 100 + '0';
        offset %= 100;
    }
    *out++ = offset / 10 + '0';
    {
        s32 rem = offset % 10;
        offset = rem;
        out[0] = offset + '0';
        out[1] = 0;
    }
}
