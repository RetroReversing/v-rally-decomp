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

s32 func_8007F894();                                /* extern */
s32 func_8007F910();                                /* extern */
s32 func_8007F984();                                /* extern */
s32 func_8007F9AC();                                /* extern */
s32 func_8007F9D4();                                /* extern */
s32 func_8007F9FC();                                /* extern */

s32 func_8007FA24(void) {
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;

    temp_s0_2 = func_8007F894();
    temp_s0_3 = temp_s0_2 | func_8007F910();
    temp_s0_4 = temp_s0_3 | func_8007F984();
    temp_s0_5 = temp_s0_4 | func_8007F9AC();
    temp_s0 = temp_s0_5 | func_8007F9D4();
    return temp_s0 | func_8007F9FC();
}
