#include "checkpoint_common.h"

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

f32 func_80088F9C(void *arg0) {
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0xC8) - 1;
    M2C_FIELD(arg0, u8 *, 0xC8) = temp_v0;
    if (!(temp_v0 & 0xFF)) {
        if (M2C_FIELD(arg0, s8 *, 0xC9) == 0) {
            M2C_FIELD(arg0, s8 *, 0xC9) = (s8) M2C_FIELD(arg0, u8 *, 0xD0);
            M2C_FIELD(arg0, u8 *, 0xC8) = (u8) M2C_FIELD(arg0, u8 *, 0xC6);
        } else {
            M2C_FIELD(arg0, s8 *, 0xC9) = 0;
            M2C_FIELD(arg0, u8 *, 0xC8) = (u8) M2C_FIELD(arg0, u8 *, 0xC7);
        }
    }
    return (f32) M2C_FIELD(arg0, s8 *, 0xC9);
}
