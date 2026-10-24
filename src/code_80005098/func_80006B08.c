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

void func_80006B08(void *arg0, s32 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5) {
    s32 temp_a1;

    temp_a1 = (arg1 & 0xFFFF) * 0x10;
    M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 0x70)), s8 *, 0xC) = arg2;
    M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 0x70)), s8 *, 0xD) = arg3;
    M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 0x70)), u8 *, 0xE) = arg4;
    M2C_FIELD((temp_a1 + M2C_FIELD(arg0, s32 *, 0x70)), u8 *, 0xF) = arg5;
}
