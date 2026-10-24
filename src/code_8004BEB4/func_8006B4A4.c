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

M2C_UNK func_800592F4(s32, s32);                    /* extern */
s32 func_8006204C(u8, u8, u8);                      /* extern */
extern void *D_800A1468;
extern M2C_UNK D_800C02AE;

s32 func_8006B4A4(s32 arg0) {
    u8 temp_a1;
    u8 temp_a1_2;
    void *temp_s0;
    void *temp_s0_2;

    temp_s0 = M2C_FIELD(&D_800C02AE, void **, 0x32F2) + ((M2C_FIELD((M2C_FIELD(&D_800C02AE, void **, 0x32F2) + M2C_FIELD(D_800A1468, s8 *, 0x228)), u8 *, 0x32) * 0x28) + 0x44);
    temp_s0_2 = temp_s0 + (func_8006204C(M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x1F), M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x21), M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0x23)) & 0xFF);
    temp_a1 = M2C_FIELD(temp_s0_2, u8 *, 0x14);
    if (temp_a1 != 0) {
        temp_a1_2 = temp_a1 - 1;
        M2C_FIELD(temp_s0_2, u8 *, 0x14) = temp_a1_2;
        func_800592F4(arg0, temp_a1_2 & 0xFF);
    }
    return 1;
}
