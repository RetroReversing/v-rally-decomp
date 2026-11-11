/* Multiplies a 3x3 matrix by a 3-vector in 4.12 fixed point and stores the
 * three results, clamped to s16, into dst. Returns dst. */
void *mat3_mul_vec3(void *mat, void *vec, void *dst)
{
    s16 *m;
    s16 *v;
    s16 out[3];
    s32 sum;
    s32 t;

    m = mat;
    v = vec;

    sum = m[0] * v[0] + m[1] * v[1] + m[2] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[0] = sum;

    sum = m[3] * v[0] + m[4] * v[1] + m[5] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[1] = sum;

    sum = m[6] * v[0] + m[7] * v[1] + m[8] * v[2];
    t = sum;
    if (sum < 0) {
        t = sum + 0xFFF;
    }
    sum = t >> 12;
    if (sum < -0x8000) {
        sum = -0x8000;
    }
    if (sum > 0x7FFF) {
        sum = 0x7FFF;
    }
    out[2] = sum;

    ((s16 *) dst)[0] = out[0];
    ((s16 *) dst)[1] = out[1];
    ((s16 *) dst)[2] = out[2];
    return dst;
}
