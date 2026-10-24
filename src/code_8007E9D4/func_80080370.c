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

void func_80080370(void *arg0, void *arg1) {
    if (arg0 == M2C_FIELD(arg1, void ***, 0)) {
        M2C_FIELD(arg1, void ***, 0) = (void **) M2C_FIELD(arg0, void ***, 4);
    } else {
        M2C_FIELD(M2C_FIELD(arg0, void **, 0), void ***, 4) = (void **) M2C_FIELD(arg0, void ***, 4);
    }
    if (arg0 == M2C_FIELD(arg1, void **, 4)) {
        M2C_FIELD(arg1, void **, 4) = (void *) M2C_FIELD(arg0, void **, 0);
        return;
    }
    *M2C_FIELD(arg0, void ***, 4) = M2C_FIELD(arg0, void **, 0);
}
