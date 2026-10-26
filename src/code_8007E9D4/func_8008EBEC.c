#include "common.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

extern void *D_800A2500;

M2C_UNK *__allocParam(void) {
    M2C_UNK *temp_v0;
    M2C_UNK *var_v1;

    temp_v0 = M2C_FIELD(D_800A2500, M2C_UNK **, 0x2C);
    var_v1 = NULL;
    if (temp_v0 != NULL) {
        var_v1 = temp_v0;
        M2C_FIELD(D_800A2500, M2C_UNK **, 0x2C) = (M2C_UNK *) *var_v1;
        *var_v1 = NULL;
    }
    return var_v1;
}
