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

void func_8008DCCC(void *arg0) {
    void **temp_v1_2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0);
    if (temp_v1 != NULL) {
        M2C_FIELD(temp_v1, void ***, 4) = (void **) M2C_FIELD(arg0, void ***, 4);
    }
    temp_v1_2 = M2C_FIELD(arg0, void ***, 4);
    if (temp_v1_2 != NULL) {
        *temp_v1_2 = M2C_FIELD(arg0, void **, 0);
    }
}
