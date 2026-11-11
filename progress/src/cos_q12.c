extern f64 D_800A4A20;
extern f64 D_800A4A28;
extern f32 __cosf(f32);

/* Cosine of a 12-bit angle (4096 units per turn), returned as a Q12 fixed-point value. */
s32 cos_q12(s32 angle)
{
    f32 radians;

    radians = (f32)(((f64)angle) * D_800A4A20);
    radians = (f32)(((f64)radians) * D_800A4A28);
    radians = __cosf(radians);
    radians *= 4096.0f;
    return (s32)radians;
}
