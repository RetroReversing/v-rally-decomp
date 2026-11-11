extern char D_800A73E0[];
s32 func_80098998(void *, s32, s32);
s32 ecvt_digits(s32, s32, s32, s32 *, s32);

/* Formats a number into a 40-digit buffer: converts it to 20 digits, then either fills the fraction with zeros or rounds the digits and returns the shared result string. */
void *func_80098E88(s32 value, s32 ndigits, s32 scale, s32 *decpt, s32 sign)
{
    s8 *digits;
    s32 exponent;
    s32 pad;

    digits = (s8 *) ecvt_digits(value, ndigits, 0x14, decpt, sign);
    exponent = *decpt;
    if (exponent != 0x7FFFFFFF) {
        pad = exponent + scale;
        if (pad >= 0) {
            if (pad < 0x14) {
                *decpt = func_80098998(&D_800A73E0[0x6B28], exponent, pad);
            } else {
                if (pad >= 0x29) {
                    pad = 0x28;
                }
                pad -= 0x14;
                digits += 0x14;
                if (pad > 0) {
                    do {
                        *digits = 0x30;
                        pad -= 1;
                        digits += 1;
                    } while (pad > 0);
                }
            }
        }
    }
    return &D_800A73E0[0x6B28];
}
