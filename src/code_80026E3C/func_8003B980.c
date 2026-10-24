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

extern M2C_UNK D_800C02AE;

void func_8003B980(void *arg0) {
    s32 temp_a2_2;
    s32 var_v0;
    u16 temp_a1;
    u32 var_a1;
    void *temp_a2;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0xA8);
    temp_a2 = M2C_FIELD(temp_v1, void **, 0x24);
    if (temp_a2 != NULL) {
        temp_a1 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0xE);
        if (((temp_a1 >= 2U) && (M2C_FIELD(temp_v1, s32 *, 0x20) & 0x880000)) || (temp_a1 == 1)) {
            var_a1 = M2C_FIELD(M2C_FIELD(temp_a2, void **, 0x4C), u32 *, 4);
            if (var_a1 < 0x7D1U) {
                var_a1 = 0x7D0;
            }
            temp_a2_2 = M2C_FIELD(M2C_FIELD(temp_a2, void **, 0x78), s32 *, 4);
            if ((var_a1 >= 0x7D1U) & (temp_a2_2 == 0x1F40)) {
                var_a1 += var_a1 >> 1;
            }
            if ((var_a1 >= 0x7D1U) & (temp_a2_2 == 0x2710)) {
                var_a1 += var_a1 >> 2;
            }
            if (var_a1 >= 0x2EE1U) {
                var_a1 = 0x2EE0;
            }
            M2C_FIELD(arg0, s16 *, 0x6C) = (s16) (var_a1 * 4);
            var_v0 = M2C_FIELD(arg0, s32 *, 0x80) & ~4;
        } else {
            var_v0 = M2C_FIELD(arg0, s32 *, 0x80) | 4;
        }
        M2C_FIELD(arg0, s32 *, 0x80) = var_v0;
    }
}
