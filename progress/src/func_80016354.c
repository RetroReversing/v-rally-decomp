extern s16 D_8009BBB6;
extern f64 D_800A4180;

/* Blends the f32 state block `cur` against `prev`: slot 14 becomes the difference of the two,
 * slot 15 drops by prev[15] minus a scalar from D_8009BBB6, slot 16 drops by prev[16], and the
 * slots 2, 7 and 12 are rescaled by D_800A4180. */
void func_80016354(f32 *cur, f32 *prev) {
    f32 x = cur[14];
    f32 y = prev[14];
    f64 scaled2 = (f64)cur[2] * D_800A4180;
    f32 h = D_8009BBB6;
    f64 scaled7 = (f64)cur[7] * D_800A4180;

    cur[14] = x - y;
    cur[15] -= prev[15] - h;
    {
        f64 scaled12 = (f64)cur[12] * D_800A4180;
        cur[16] -= prev[16];
        cur[2] = scaled2;
        cur[7] = scaled7;
        cur[12] = scaled12;
    }
}
