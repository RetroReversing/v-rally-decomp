#include "decompdecomp_sync_e4df60a9d409958455db.h"
#line 1 "func.c"
void *mat3_mul_vec3(void *, void *, void *);

void *func_8002E514(void *mat, void *vec, void *dst)
{
    /* Thin wrapper: applies a 3x3 matrix to a 3-vector and returns dst. */
    return mat3_mul_vec3(mat, vec, dst);
}

