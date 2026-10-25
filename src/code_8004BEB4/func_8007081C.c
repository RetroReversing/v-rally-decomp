#include "common.h"

void func_800592F4(s32, s32);
extern u8 D_800AE850[];

s32 func_8007081C(void) {
    s32 var_a1;

    if (D_800AE850[0x7FC8] == 0) {
        D_800AE850[0x7FC8] = 1;
        var_a1 = 1;
    } else {
        D_800AE850[0x7FC8] = 0;
        var_a1 = 0;
    }
    func_800592F4(7, var_a1);
    return 0;
}
