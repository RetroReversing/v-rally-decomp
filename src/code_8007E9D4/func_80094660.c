#include "common.h"

s32 func_8008ACA0();
s32 func_8008D4A0();
extern s32 D_800A39A0;
extern char D_800A73E0[];
extern char D_800AE850[];

void func_80094660(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x87A8;
    D_800A39A0 = 1;
    func_8008ACA0(temp_s0, D_800A73E0 + 0x6AF0, 1);
    func_8008D4A0(temp_s0, 0, 0);
}
