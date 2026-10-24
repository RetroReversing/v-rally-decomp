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

void *func_8004240C(M2C_UNK);                       /* extern */

s32 func_80042440(s32 arg0, M2C_UNK arg1) {
    void *temp_v0;

    temp_v0 = func_8004240C(arg1);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x24) = arg0;
        return 1;
    }
    return 0;
}
