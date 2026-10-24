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

extern void *D_800A1468;
extern M2C_UNK D_800AE850;

void func_8005A510(s8 arg0, s32 arg1) {
    M2C_FIELD(&D_800AE850, s8 *, 0x120C) = arg0;
    if (arg1 & 0xFF) {
        M2C_FIELD(D_800A1468, s8 *, 0x29E) = 1;
    }
    M2C_FIELD(D_800A1468, s8 *, 0x2BB) = 2;
}
