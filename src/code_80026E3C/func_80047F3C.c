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

s32 func_8004240C(s32);                             /* extern */
M2C_UNK func_800480B0(s32, s32);                    /* extern */
M2C_UNK func_80048878(s32, s32);                    /* extern */

void func_80047F3C(s32 arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = func_8004240C((((arg1 & 0xFF) - 1) * 2) | 1);
    func_800480B0(temp_v0, arg0);
    func_80048878(temp_v0, arg0);
}
