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



s32 func_8007ED48();
s32 osCreateThread();
s32 osStartThread();

s32 func_8007FB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;

    var_s2 = arg0;
    var_s3 = arg2;
    var_s4 = arg3;
    var_s1 = arg1 + 0x1B0;
    var_v0 = var_s1;
    if (var_s1 < 0) {
        var_v0 = arg1 + 0x1B7;
    }
    var_s1 += var_s1 - ((var_v0 >> 3) * 8);
    var_s0 = func_8007ED48(1, arg1 + 0x1B0, 8);
    osCreateThread(var_s0, var_s2, var_s2, var_s4, var_s0 + var_s1, var_s3);
    osStartThread(var_s0);
    return var_s0;
}
