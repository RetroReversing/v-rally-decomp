/* Scales the vector (x, y, z) in place to unit length. */
void guNormalize(f32 *x, f32 *y, f32 *z) {
    f32 vx;
    f32 vy;
    f32 vz;
    f32 inv_len;

    vx = *x;
    vy = *y;
    vz = *z;
    inv_len = 1.0f / sqrtf((vx * vx) + (vy * vy) + (vz * vz));
    *x *= inv_len;
    *y *= inv_len;
    *z *= inv_len;
}
