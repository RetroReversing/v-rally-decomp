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

s32 func_8002E850(s32 arg0) {
    s32 var_a0;
    s32 var_v0;

    var_v0 = arg0;
    if (arg0 < 0) {
        var_v0 = arg0 + 0xFFF;
    }
    var_a0 = arg0 - ((var_v0 >> 0xC) << 0xC);
    if (var_a0 >= 0x800) {
        var_a0 -= 0x1000;
    }
    if (var_a0 < -0x800) {
        var_a0 += 0x1000;
    }
    return var_a0;
}
