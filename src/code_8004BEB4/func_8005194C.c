#include "common.h"

s32 func_80022184();
s32 func_80022200();
s32 func_80035438();
extern s32 D_800A1240;
extern char D_800AE850[];

void func_8005194C(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x73E0;
    if (func_80022184(temp_s0) != 0) {
        func_80022200(temp_s0);
        func_80035438(D_800A1240);
    }
}
