typedef struct V3 { s32 x; s32 y; s32 z; } V3;

/* Componentwise square: dst = src * src, for each of x, y and z. */
void func_8002E778(V3 *src, V3 *dst)
{
    dst->x = src->x * src->x;
    dst->y = src->y * src->y;
    dst->z = src->z * src->z;
}
