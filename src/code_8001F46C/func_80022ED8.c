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

M2C_UNK func_800229C0(s32, void *);                 /* extern */

void func_80022ED8(void *arg0) {
    s32 var_a0;
    s32 var_s0;
    void *var_a1;

    var_s0 = 0;
    do {
        var_a0 = M2C_FIELD(arg0, s32 *, 0xA0);
        if ((~var_a0 != 0) & (var_a0 != var_s0)) {
            var_a1 = arg0;
            do {
                var_a1 += 4;
                var_a0 = M2C_FIELD(var_a1, s32 *, 0xA0);
            } while ((~var_a0 != 0) & (var_a0 != var_s0));
        }
        if (var_a0 != -1) {
            func_800229C0(var_a0, arg0);
        }
        var_s0 += 1;
    } while (var_s0 < 0xB);
}
