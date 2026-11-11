void mat3x3MulQ12(void *a, void *b, void *c);
void mat3_mul_vec3_q12(void *a, s32 *b, s32 *c);

/* Composes two Q12 transforms: the 3x3 rotation part is multiplied out, and the
   translation (words 5..7) becomes rotation * src translation + dst translation. */
void func_8002E54C(s32 *rot, s32 *src, s32 *dst)
{
    s32 srcTrans[3];
    s32 rotTrans[3];

    mat3x3MulQ12(rot, src, dst);
    srcTrans[0] = src[5];
    srcTrans[1] = src[6];
    srcTrans[2] = src[7];
    mat3_mul_vec3_q12(rot, srcTrans, rotTrans);
    dst[5] = rotTrans[0] + rot[5];
    dst[6] = rotTrans[1] + rot[6];
    dst[7] = rotTrans[2] + rot[7];
}
