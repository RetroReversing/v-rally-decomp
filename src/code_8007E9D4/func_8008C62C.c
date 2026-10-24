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

void func_8008C62C(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    *arg4 = (M2C_FIELD(arg0, f32 *, 0) * arg1) + (M2C_FIELD(arg0, f32 *, 0x10) * arg2) + (M2C_FIELD(arg0, f32 *, 0x20) * arg3) + M2C_FIELD(arg0, f32 *, 0x30);
    *arg5 = (M2C_FIELD(arg0, f32 *, 4) * arg1) + (M2C_FIELD(arg0, f32 *, 0x14) * arg2) + (M2C_FIELD(arg0, f32 *, 0x24) * arg3) + M2C_FIELD(arg0, f32 *, 0x34);
    *arg6 = (M2C_FIELD(arg0, f32 *, 8) * arg1) + (M2C_FIELD(arg0, f32 *, 0x18) * arg2) + (M2C_FIELD(arg0, f32 *, 0x28) * arg3) + M2C_FIELD(arg0, f32 *, 0x38);
}
