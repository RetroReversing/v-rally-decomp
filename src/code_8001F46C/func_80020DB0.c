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

void func_80020DB0(void *arg0) {
    s32 temp_a1;
    void *temp_a0;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x6C);
    M2C_FIELD(temp_v1, s32 *, 4) = (s32) (M2C_FIELD(temp_v1, s32 *, 4) + 1);
    if (M2C_FIELD(&D_800C02AE, u8 *, 0x7681) == 3) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x6C);
        temp_a1 = M2C_FIELD(temp_a0, s32 *, 4);
        if (temp_a1 == ((M2C_FIELD(temp_a0, s32 *, 4) / 3) * 3)) {
            M2C_FIELD(temp_a0, s32 *, 4) = (s32) (temp_a1 + 1);
        }
    }
}
