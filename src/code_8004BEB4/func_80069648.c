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

void *func_800592AC(M2C_UNK);                       /* extern */
extern void *D_800A1468;

void func_80069648(void) {
    s16 var_a0;
    void *temp_v0;

    M2C_FIELD(D_800A1468, s8 *, 0x24E) = 1;
    temp_v0 = func_800592AC(0);
    var_a0 = 0x1A4;
    if (M2C_FIELD(D_800A1468, s8 *, 0x228) != 0) {
        var_a0 = 0x1AB;
    }
    M2C_FIELD(temp_v0, s16 *, 8) = var_a0;
}
