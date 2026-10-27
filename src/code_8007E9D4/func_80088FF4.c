#include "common.h"

/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */
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

M2C_UNK alSynSetPitch(void *, s32, f32);            /* extern */
f32 func_80089300(f32);                 /* extern */
extern f64 D_800A6D40;
extern u8 D_800AE850[];
extern M2C_UNK D_800C02AE;

void func_80088FF4(void *arg0, s32 arg1, f32 arg2) {
    f32 temp_ft0;
    f64 scaled;
    f32 var_ft1;
    s32 temp_v1;
    s32 modulation;
    u16 temp_a0;
    u8 temp_a0_2;
    u8 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u8 *, 0xB0);
    var_ft1 = M2C_FIELD(arg0, f32 *, 0x28);
    temp_v1 = temp_v0 & 0xFF;
    if (temp_v1 != 0) {
        temp_a0 = M2C_FIELD(arg0, u16 *, 0xA2);
        if (temp_v0 >= temp_a0) {
            temp_ft0 = M2C_FIELD(arg0, f32 *, 0x48);
            var_ft1 = temp_ft0 + (((var_ft1 - temp_ft0) / (f32) temp_v1) * (f32) temp_a0);
        }
        M2C_FIELD(arg0, f32 *, 0x4C) = var_ft1;
    }
    temp_a0_2 = M2C_FIELD(arg0, u8 *, 0xB2);
    modulation = M2C_FIELD(arg0, s8 *, 0xB1) * (1 - temp_a0_2);
    var_ft1 = var_ft1 + (arg2 + M2C_FIELD(arg0, f32 *, 0x20) + (f32)modulation);
    M2C_FIELD(arg0, u8 *, 0xB2) = 0U;
    if (var_ft1 != M2C_FIELD(arg0, f32 *, 0x24)) {
        scaled = (f64)var_ft1 * D_800A6D40;
        M2C_FIELD(arg0, f32 *, 0x24) = var_ft1;
        alSynSetPitch(D_800AE850 + 0x2304, M2C_FIELD(&D_800C02AE, s32 *, 0x7576) + (arg1 * 0x1C), func_80089300((f32)scaled));
    }
}
