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

M2C_UNK func_80047EE4();                            /* extern */
M2C_UNK func_800802A0(s32, M2C_UNK);                /* extern */
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

s32 func_8004804C(void) {
    u32 var_s0;
    u8 temp_v0;

    func_80047EE4();
    temp_v0 = M2C_FIELD(M2C_FIELD(&D_800C02AE, void **, 0x32F2), u8 *, 0xF);
    var_s0 = 1;
    if (temp_v0 != 0) {
        do {
            var_s0 += 1;
            func_800802A0(M2C_FIELD(&D_800AE850, s32 *, 0x6D94), 0x94);
        } while (temp_v0 >= var_s0);
    }
    return 1;
}
