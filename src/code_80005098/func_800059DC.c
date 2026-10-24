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

s32 func_8000E09C(void *, s32);                     /* extern */
void *func_8007EAA0(M2C_UNK, M2C_UNK);              /* extern */
M2C_UNK func_8007EE9C(void *);                      /* extern */

void *func_800059DC(s32 arg0, M2C_UNK arg1, s32 arg2) {
    void *temp_v0;
    void *var_v0;

    temp_v0 = func_8007EAA0(arg1, 0x28);
    var_v0 = temp_v0;
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x10) = arg2;
        var_v0 = temp_v0;
        if (!(func_8000E09C(temp_v0, arg0) & 0xFF)) {
            func_8007EE9C(temp_v0);
            var_v0 = NULL;
        }
    }
    return var_v0;
}
