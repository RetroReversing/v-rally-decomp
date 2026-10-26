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

extern void *D_800C607C;

void func_8001E600(void *arg0) {
    M2C_FIELD(D_800C607C, s8 *, 0x2E) = 1;
    M2C_FIELD(D_800C607C, s8 *, 0x2F) = (s8) ((s32) M2C_FIELD(arg0, s32 *, 0x90) / 2);
}
