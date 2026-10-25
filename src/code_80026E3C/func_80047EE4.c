#include "common.h"

s32 func_80022184();
s32 func_800221D4();
s32 func_80080440();
extern char D_800AE850[];
extern s32 func_80047F94;

s32 func_80047EE4(void)
{
    void *temp_s0;
    s32 ret;

    temp_s0 = D_800AE850 + 0x7348;
    if (func_80022184(temp_s0)) {
        ret = 0;
    } else {
        *((s32 *) (D_800AE850 + 0x6D94)) = func_80080440();
        func_800221D4(temp_s0, &func_80047F94);
        ret = 1;
    }
    return ret;
}
