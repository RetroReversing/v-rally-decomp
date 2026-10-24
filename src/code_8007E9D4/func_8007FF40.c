#include "common.h"

s32 func_8008ACD0();
s32 func_8008BB80();
s32 func_8008DFC0();
extern char D_800A73E0[];
extern char D_800AE850[];
extern s32 func_8007FF9C;

void func_8007FF40(void) {
    void *temp_s0;

    func_8008BB80();
    temp_s0 = D_800A73E0 + 0x38;
    func_8008ACD0(temp_s0, 1, &func_8007FF9C, 0, D_800AE850 + 0x7D50, 1);
    func_8008DFC0(temp_s0);
}
