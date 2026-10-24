#include "common.h"

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



extern f64 D_800A54E8;

void func_8005F014(s32 arg0, f32 *arg1) {
    f32 var_fv0;
    f64 temp_fv0;

    temp_fv0 = (f64) *arg1;
    if (D_800A54E8 < temp_fv0) {
        var_fv0 = (f32) (temp_fv0 - D_800A54E8);
    } else {
        var_fv0 = 0.0f;
    }
    *arg1 = var_fv0;
}
