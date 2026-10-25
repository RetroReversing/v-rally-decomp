#include "common.h"

s32 func_80035438();
extern int D_800AE850[];

void func_800693CC(void)
{
    u8 i;

    for (i = 0; i < 9; i++) {
        func_80035438(*(s32 *)((char *)D_800AE850 + 0x87F8 + i * 4));
    }
}
