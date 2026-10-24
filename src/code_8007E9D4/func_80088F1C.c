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

f32 func_8008D950(f32);                             /* extern */
extern f64 D_800A6D38;

f32 func_80088F1C(void *arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u16 *, 0xA2) - M2C_FIELD(arg0, u8 *, 0xAE);
    if (temp_v1 > 0) {
        M2C_FIELD(arg0, f32 *, 0x64) = (f32) (func_8008D950((f32) ((f64) (2.0f * ((f32) temp_v1 / (f32) M2C_FIELD(arg0, u8 *, 0xCD))) * D_800A6D38)) * M2C_FIELD(arg0, f32 *, 0x1C));
    }
    return M2C_FIELD(arg0, f32 *, 0x64);
}
