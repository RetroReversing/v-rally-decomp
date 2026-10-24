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

s32 func_8001FEDC();                                /* extern */
M2C_UNK func_800306A8(M2C_UNK, s32, M2C_UNK);       /* extern */

void func_80033DB8(s32 arg0, M2C_UNK arg1, s32 arg2, M2C_UNK arg3) {
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8001FEDC();
    var_v1 = (-(temp_v0 >= 0x1388) & 5) | 4;
    if (temp_v0 < 0xBB8) {
        var_v1 = 3;
    }
    if (temp_v0 < 0x3E8) {
        var_v1 = 2;
    }
    func_800306A8(arg1, arg2 + var_v1, arg3);
}
