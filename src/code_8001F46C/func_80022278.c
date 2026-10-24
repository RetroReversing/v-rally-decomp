#include "common.h"

s32 func_80022184();
s32 func_800221C4();
s32 func_80080440();
s32 func_80097E30();
extern char D_800AE850[];

void func_80022278(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7390;
    if (func_80022184(temp_s0) == 0) {
        func_80097E30(temp_s0 - 0x88, 0, 0xE8);
        *(s32 *)(D_800AE850 + 0x2370) = func_80080440();
        func_800221C4(temp_s0);
    }
}
