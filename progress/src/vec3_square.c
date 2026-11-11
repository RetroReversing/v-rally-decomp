typedef struct V3 { s32 x; s32 y; s32 z; } V3;

/* Component-wise square: out = in * in for x, y and z. */
void vec3_square(V3 *in, V3 *out)
{
    out->x = in->x * in->x;
    out->y = in->y * in->y;
    out->z = in->z * in->z;
}
