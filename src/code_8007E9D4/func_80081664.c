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

s32 func_8008188C(M2C_UNK, s32);                    /* extern */
M2C_UNK func_8008F540();                            /* extern */

s32 func_80081664(s32 arg0, M2C_UNK arg1) {
    s32 temp_s0;

    temp_s0 = func_8008188C(arg1, arg0);
    func_8008F540();
    return temp_s0;
}
