extern f64 D_800A4A40;
void func_8001C1A8(f32 *);

/* Converts a packed s16 rotation (x, y, z) to degrees, scaling each axis by
 * 0x168 (360) and the constant D_800A4A40, then passes the angles on. */
void func_8002DF40(s16 *rot) {
    f32 angles[4];

    angles[0] = (f32) ((f64) (rot[0] * 0x168) * D_800A4A40);
    angles[1] = (f32) ((f64) (rot[1] * 0x168) * D_800A4A40);
    angles[2] = (f32) ((f64) (rot[2] * 0x168) * D_800A4A40);
    func_8001C1A8(angles);
}
