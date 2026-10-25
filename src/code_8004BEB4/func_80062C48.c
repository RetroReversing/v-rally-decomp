#include "common.h"

extern u8 D_800C02AE[];
s32 func_800592F4();

s32 func_80062C48(s32 arg0) {
    u8 v;

    v = *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0x30);
    if (v != 0) {
        if (v < 9) {
            *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0x30) = v + 1;
        } else {
            *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0x30) = 0;
        }
    }
    func_800592F4(arg0, *(u8 *)(*(char **)(D_800C02AE + 0x32F2) + 0x30));
    return 0;
}
