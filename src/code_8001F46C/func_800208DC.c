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

void func_800208DC(void *arg0) {
    s32 temp_v1;
    s32 var_a2;
    u32 var_a1;
    void *temp_v0;
    void *temp_v1_2;

    var_a1 = 0;
    var_a2 = 0x18;
    do {
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x88);
        temp_v0 = M2C_FIELD(((var_a1 * 4) + temp_v1), void **, 8);
        temp_v1_2 = temp_v1 + var_a2;
        M2C_FIELD(temp_v1_2, s32 *, 0) = (s32) M2C_FIELD(temp_v0, f32 *, 0x38);
        M2C_FIELD(temp_v1_2, s32 *, 4) = (s32) M2C_FIELD(temp_v0, f32 *, 0x3C);
        var_a1 += 1;
        M2C_FIELD(temp_v1_2, s32 *, 8) = (s32) M2C_FIELD(temp_v0, f32 *, 0x40);
        var_a2 += 0x14;
    } while (var_a1 < 4U);
}
