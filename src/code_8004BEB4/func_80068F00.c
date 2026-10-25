#include "common.h"

extern u8 *D_800A1468;
extern u8 D_800A1683;
extern u8 D_800C02AE[];
s32 func_800671A0(s32, s32);
s32 func_8006F0E0(u8, void *, s32);
s32 func_8006F75C(void);

s32 func_80068F00(void) {
    s32 var_a2;
    s32 idx;
    u8 i;
    u8 temp_v0;
    u8 *base;

    var_a2 = 0;
    i = 0;
    do {
        temp_v0 = *(&D_800A1683 - i);
        var_a2 = var_a2 << 4;
        i++;
        var_a2 |= temp_v0;
    } while (i < 8);
    idx = (s8)D_800A1468[0x22A];
    base = *(u8 **)(D_800C02AE + 0x32F2);
    *(s32 *)(base + ((idx * 5) << 3) + 0x68) = var_a2;
    func_8006F0E0((s8)D_800A1468[0x22A], D_800A1468, var_a2);
    func_8006F75C();
    func_800671A0(0, 0);
    return 0;
}
