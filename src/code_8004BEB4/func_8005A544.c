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

void *func_800592D0();                              /* extern */

void func_8005A544(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    void *temp_v0;

    temp_v0 = func_800592D0();
    M2C_FIELD(temp_v0, s8 *, 0xB) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0xC) = arg2;
    M2C_FIELD(temp_v0, s8 *, 0xD) = arg3;
}
