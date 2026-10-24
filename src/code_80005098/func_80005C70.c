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

s32 func_8000DC70(M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */

s32 func_80005C70(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_a3;
    s32 var_v1;

    var_v1 = arg1;
    var_a3 = arg2;
    if (var_v1 == 0) {
        var_v1 = 0x400;
    }
    if (var_a3 == 0) {
        var_a3 = 0x20;
    }
    return func_8000DC70(0, 0, var_v1, var_a3, arg0 & 0xFFFF) & 0xFF;
}
