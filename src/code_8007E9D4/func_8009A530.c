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

M2C_UNK func_8009A6C4();                            /* extern */

s8 func_8009A530(s8 *arg0) {
    s32 temp_v0;
    s32 var_a1;
    s8 *var_s0;
    u8 var_a0;

    var_s0 = arg0;
    func_8009A6C4();
    var_a0 = (u8) *var_s0;
    var_a1 = 0;
    if (*var_s0 != 0) {
        do {
            var_s0 += 1;
            temp_v0 = var_a0 << 0x18;
            var_a0 = (u8) *var_s0;
            var_a1 = temp_v0 >> 0x18;
        } while (*var_s0 != 0);
    }
    return (s8) var_a1;
}
