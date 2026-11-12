/* Adds two 3-component s32 vectors: out = a + b. */
void vec3_add(s32 *a, s32 *b, s32 *out) {
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}
