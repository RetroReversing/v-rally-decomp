typedef struct Vec3S32 { s32 x, y, z; } Vec3S32;

/* Linear blend of two 3-component integer vectors: out = a * scaleA + b * scaleB, per component. */
void func_8002D460(void *a, void *b, s32 scaleA, s32 scaleB, void *out) {
    ((Vec3S32 *) out)->x = (s32) ((((Vec3S32 *) a)->x * scaleA) + (((Vec3S32 *) b)->x * scaleB));
    ((Vec3S32 *) out)->y = (s32) ((((Vec3S32 *) a)->y * scaleA) + (((Vec3S32 *) b)->y * scaleB));
    ((Vec3S32 *) out)->z = (s32) ((((Vec3S32 *) a)->z * scaleA) + (((Vec3S32 *) b)->z * scaleB));
}
