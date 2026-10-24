#include "common.h"

s32 func_80081E8C();
s32 func_80082290();
s32 func_800847CC();
s32 func_800848A0();
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80084A3C(s32 arg0) {
    s32 *temp_v0;

    temp_v0 = *(s32 *)(D_800AE850 + 0x8AE0) + (arg0 * 8);
    *(s32 * *)(D_800AE850 + 0x8AE4) = temp_v0;
    func_800848A0(*temp_v0);
    func_80081E8C((D_800AE850 + 0x8AE0) - 8, 4);
    func_800847CC();
    func_80082290(*(u16 *)(D_800C02AE + 0x30C6));
}
