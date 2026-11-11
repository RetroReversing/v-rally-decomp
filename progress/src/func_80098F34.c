extern u8 D_800A73E0[];
extern u8 *ecvt_digits(s32, s32, s32, s32 *, s32 *);
extern s32 copyStringAligned(u8 *);
extern s32 func_8008E13C(u8 *, u8 *, s32);

/* Formats a floating-point value into buf in %g style: ndigits significant digits, with
 * a leading '-' for negatives, trailing zeros removed unless the flag at D_800A73E0+0x6b24
 * is set, and exponent form for large or small magnitudes. Returns buf. */
u8 *func_80098F34(s32 value_hi, s32 value_lo, s32 ndigits, u8 *buf)
{
    s32 decpt, sign;
    u8 *digits, *out, *p;

    digits = ecvt_digits(value_hi, value_lo, ndigits, &decpt, &sign);
    out = buf;
    if (sign) { *buf = '-'; out = buf + 1; }
    if (decpt == 0x7fffffff) { copyStringAligned(out); return buf; }
    if (decpt <= 0) {
        if (decpt >= -3) {
            *out++ = '0';
            *out++ = '.';
            p = out;
            if (decpt) do { *p++ = '0'; decpt = decpt + 1; } while (decpt);
            func_8008E13C(p, digits, ndigits);
            out = p + ndigits;
strip_zeros:
            if (*(s8 *)(D_800A73E0 + 0x6b24)) *out = 0;
            else {
                if (((s8 *)out)[-1] == 0x30) do { out--; } while (((s8 *)out)[-1] == 0x30);
                out -= ((s8 *)out)[-1] == 0x2e;
                *out = 0;
            }
            return buf;
        }
        goto exp_format;
    }
    if (decpt < ndigits) {
        ndigits--;
        if (ndigits != -1) do {
            *out++ = *digits++;
            decpt = decpt - 1;
            if (decpt == 0) *out++ = '.';
            ndigits--;
        } while (ndigits != -1);
        goto strip_zeros;
    } else if (ndigits + 1 >= decpt) {
        func_8008E13C(out, digits, decpt);
        out[ndigits] = '0';
        if (!*(s8 *)(D_800A73E0 + 0x6b24)) out[decpt] = 0;
        else { out[decpt] = '.'; (out + decpt)[1] = 0; }
    } else {
exp_format:
        func_80098A1C(digits, ndigits, decpt - 1, out);
    }
    return buf;
}
