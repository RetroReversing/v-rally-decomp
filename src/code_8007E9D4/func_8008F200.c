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

s32 func_8008BD90();                                /* extern */
M2C_UNK func_8008BDB0(s32);                         /* extern */
extern void *D_800A3A34;

void func_8008F200(s32 arg0, s32 arg1, s16 arg2) {
    s32 temp_a0;

    temp_a0 = func_8008BD90();
    M2C_FIELD(D_800A3A34, s32 *, 0x10) = arg0;
    M2C_FIELD(D_800A3A34, s32 *, 0x14) = arg1;
    M2C_FIELD(D_800A3A34, s16 *, 2) = arg2;
    func_8008BDB0(temp_a0);
}
