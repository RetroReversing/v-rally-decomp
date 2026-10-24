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

s32 func_8007FA24();                                /* extern */
s32 func_8007FA70();                                /* extern */
M2C_UNK func_80080070();                            /* extern */
s32 func_80081030();                                /* extern */

s32 func_80080080(void) {
    s32 var_v0;

    func_80080070();
    var_v0 = 0;
    if (func_8007FA24() != 0) {
        var_v0 = 0;
        if (func_8007FA70() != 0) {
            var_v0 = func_80081030() != 0;
        }
    }
    return var_v0;
}
