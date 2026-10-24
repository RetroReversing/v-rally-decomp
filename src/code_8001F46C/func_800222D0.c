#include "common.h"

s32 func_80022184();
s32 func_80022200();
s32 func_80080478();
extern char D_800AE850[];

void func_800222D0(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7390;
    if (func_80022184(temp_s0) != 0) {
        func_80080478(*(s32 *)(D_800AE850 + 0x2370));
        func_80022200(temp_s0);
    }
}
