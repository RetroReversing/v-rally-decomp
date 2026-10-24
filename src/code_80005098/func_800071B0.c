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

s32 func_800071B0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x14);
    M2C_FIELD(temp_v1, s32 *, 0) = (s32) (((arg1 & 0x1F) << 0x11) | ((arg2 & 0x1F) << 9) | ((arg3 & 0x1F) * 2) | 0x05000000);
    M2C_FIELD(temp_v1, s32 *, 4) = 0;
    return 1;
}
