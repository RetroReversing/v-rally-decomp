/* Normalizes the 3-vector at src into dst and returns its length. A zero-length input uses a divisor of 1, so dst gets the input unchanged. */
f32 vec3Normalize(f32 *src, f32 *dst) {
    f32 x, len, y, z, q;
    x = src[0];
    y = src[1];
    z = src[2];
    len = (x * x + y * y);
    len += z * z;
    z = __builtin_sqrtf(len);
    if (z == 0.0f) z = 1.0f;
    len = x / z;
    dst[0] = len;
    q = z;
    dst[1] = src[1] / q;
    dst[2] = src[2] / z;
    return z;
}
