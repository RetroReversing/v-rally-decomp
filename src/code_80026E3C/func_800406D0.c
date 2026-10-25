#include "common.h"

s32 func_80022184();
s32 func_800221D4();
extern char D_800AE850[];
extern s32 func_80040694;
s32 func_800406D0(void)
{
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7310;
    if (func_80022184(temp_s0) != 0) {
        return 0;
    }
    func_800221D4(temp_s0, &func_80040694);
    return 1;
}
