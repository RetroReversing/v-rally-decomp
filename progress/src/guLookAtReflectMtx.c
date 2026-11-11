s32 guLookAtReflectF(void *a0, s32 a1, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10);
s32 guMtxF2L(void *a0, s32 a1);

/* Builds a reflection look-at matrix in a float temp, then converts it to the fixed-point Mtx at mtx. */
void guLookAtReflectMtx(s32 mtx, s32 lookAt, s32 a2, s32 a3, f32 a4, f32 a5, f32 a6, f32 a7, f32 a8, f32 a9, f32 a10) {
    s32 buf[16];

    guLookAtReflectF(buf, lookAt, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    guMtxF2L(buf, mtx);
}
