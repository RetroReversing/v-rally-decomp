#include "checkpoint_common.h"

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

f32 _getVol(f32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_ft0;
    f32 var_fv1;
    s32 var_a1;
    s32 var_v1;

    var_a1 = arg1 >> 3;
    if (var_a1 == 0) {
        return arg0;
    }
    var_ft0 = 1.0f;
    var_v1 = 0;
    var_fv1 = ((f32) (arg2 << 0x10) + (f32) (arg3 & 0xFFFF)) / 65536.0f;
loop_3:
    if (var_a1 & 1) {
        var_ft0 *= var_fv1;
    }
    var_a1 = var_a1 >> 1;
    if (var_a1 != 0) {
        var_v1 += 1;
        var_fv1 *= var_fv1;
        if (var_v1 >= 0x20) {

        } else {
            goto loop_3;
        }
    }
    return arg0 * var_ft0;
}
