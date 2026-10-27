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

M2C_UNK func_8005803C(M2C_UNK, M2C_UNK);            /* extern */
s32 func_80068130();                                /* extern */
M2C_UNK func_8006D564(u8);                          /* extern */
M2C_UNK func_8006E8A0();                            /* extern */
M2C_UNK func_8006EE3C(u8);                          /* extern */
M2C_UNK func_8006F424();           /* extern */
extern void *D_800A1468;
extern s32 D_800A1630;
extern M2C_UNK D_800AE850;
extern M2C_UNK D_800C02AE;

s32 func_800684F4(void) {
    s32 temp_a2;
    s32 var_a1;
    s8 temp_a3;

    temp_a3 = M2C_FIELD(D_800A1468, s8 *, 0x229);
    temp_a2 = (((u32) M2C_FIELD(&D_800C02AE, u32 *, 0x6E62) >> 4) & 0xF) != temp_a3;
    var_a1 = temp_a2;
    if ((((u32) M2C_FIELD(&D_800C02AE, u32 *, 0x6E62) >> 8) & 3) == 2) {
        var_a1 = temp_a2 & -((M2C_FIELD(&D_800C02AE, u32 *, 0x6E62) & 0xF) != temp_a3);
    }
    if (!(var_a1 & 0xFF)) {
        M2C_FIELD(&D_800AE850, s8 *, 0x7FCA) = 0;
        func_8006F424();
        func_8006E8A0();
    }
    func_8006D564((u8) M2C_FIELD(D_800A1468, s8 *, 0x229));
    func_8006EE3C((u8) M2C_FIELD(D_800A1468, s8 *, 0x229));
    func_8005803C(0, 0);
    M2C_FIELD(D_800A1468, s8 *, 0x24D) = 0;
    D_800A1630 = func_80068130();
    return 0;
}
