/* Cross product a x b of two vectors, scaled down by 4096 (>> 12) with round-toward-zero for
 * negative values, so the result is in the same fixed-point format as the inputs. */
void vec3CrossFixed(s32 *a, s32 *b, s32 *out) {
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    x = a[1] * b[2] - a[2] * b[1];
    y = a[2] * b[0] - a[0] * b[2];
    z = a[0] * b[1] - a[1] * b[0];
    t = x;
    if (x < 0) {
        t = x + 0xFFF;
    }
    x = t >> 12;
    t = y;
    if (y < 0) {
        t = y + 0xFFF;
    }
    y = t >> 12;
    t = z;
    if (z < 0) {
        t = z + 0xFFF;
    }
    z = t >> 12;
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
