/* Scales vol by a fixed-point ratio raised to the power (steps >> 3). The ratio is
 * (ratio_hi << 16 | (ratio_lo & 0xFFFF)) / 65536, and the power is found by repeated
 * squaring, at most 32 times. Returns vol unchanged when steps < 8. */
f32 vol_scale_pow(f32 vol, s32 steps, s32 ratio_hi, s32 ratio_lo)
{
    f32 factor;
    f32 base;
    s32 n;
    s32 i;

    n = steps >> 3;
    if (n == 0) {
        return vol;
    }
    factor = 1.0f;
    i = 0;
    base = ((f32)(ratio_hi << 0x10) + (f32)(ratio_lo & 0xFFFF)) / 65536.0f;
loop_3:
    if (n & 1) {
        factor *= base;
    }
    n = n >> 1;
    if (n != 0) {
        i += 1;
        base *= base;
        if (i >= 0x20) {
        } else {
            goto loop_3;
        }
    }
    return vol * factor;
}
