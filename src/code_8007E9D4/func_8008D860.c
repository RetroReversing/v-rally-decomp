#include "common.h"

s32 func_8008ACA0();
s32 func_8008D4A0();
extern s32 D_800A1CF0;
extern char D_800A73E0[];
extern char D_800C02AE[];

void func_8008D860(void) {
    void *temp_s0;

    temp_s0 = D_800C02AE + 0x10312;
    D_800A1CF0 = 1;
    func_8008ACA0(temp_s0, D_800A73E0 + 0x45B0, 1);
    func_8008D4A0(temp_s0, 0, 0);
}
