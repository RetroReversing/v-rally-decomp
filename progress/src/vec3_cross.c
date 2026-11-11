/* Cross product of two 3-component vectors: out = a x b. Components are s32. */
void vec3_cross(s32 *a, s32 *b, s32 *out) {
    s32 x;
    s32 y;
    s32 z;

    x = a[1] * b[2] - a[2] * b[1];
    y = a[2] * b[0] - a[0] * b[2];
    z = a[0] * b[1] - a[1] * b[0];
    out[0] = x;
    out[1] = y;
    out[2] = z;
}
