extern f64 D_800A4A30;
extern f64 D_800A4A38;
extern f32 __sinf(f32);

/* Sine of a 4096-step angle, returned as 4.12 fixed point. */
s32 sin_q12(s32 angle)
{
    f32 x;
    x = (f32)(((f64)angle) * D_800A4A30);
    x = (f32)(((f64)x) * D_800A4A38);
    x = __sinf(x);
    x *= 4096.0f;
    return (s32)x;
}
