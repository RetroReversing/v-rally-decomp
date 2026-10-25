#include "common.h"

s32 func_80022184();
s32 func_80022200();
void func_80080478();
void func_800804C4();
extern char D_800AE850[];
void func_80042AB0(void);

s32 func_80042ACC(void)
{
    char *temp_s0;
    temp_s0 = D_800AE850 + 0x73E8;
    if (func_80022184(temp_s0) != 0) {
        func_800804C4(*(s32 *)(D_800AE850 + 0x2354), func_80042AB0);
        func_80080478(*(s32 *)(D_800AE850 + 0x2354));
        func_80022200(temp_s0);
        return 1;
    }
    return 0;
}
