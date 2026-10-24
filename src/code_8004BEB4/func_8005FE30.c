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

M2C_UNK func_800592F4(M2C_UNK, M2C_UNK);            /* extern */
extern M2C_UNK D_800C02AE;

s32 func_8005FE30(void) {
    M2C_UNK var_a1;
    u16 temp_v1;

    temp_v1 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x2C);
    var_a1 = 0;
    if (temp_v1 & 0x4000) {
        M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x2C) = (u16) (temp_v1 & 0xBFFF);
    } else {
        M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u16 *, 0x2C) = (u16) (temp_v1 | 0x4000);
        var_a1 = 1;
    }
    func_800592F4(0x1E, var_a1);
    return 0;
}
