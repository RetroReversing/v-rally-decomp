#include "common.h"

extern s32 D_800AE858;
s32 func_80038A8C();
extern char D_800AE850[];

void func_8003BE44(char *arg0)
{
    s16 temp_v1;

    *((u16 *) (arg0 + 0x7A)) += 1;
    *((u8 *) (arg0 + 0x93)) = 0xC8;
    temp_v1 = *((s16 *) (arg0 + 0x7A));
    if (temp_v1 == 4)
    {
        *((s32 *) (arg0 + 0x80)) = (*((s32 *) (arg0 + 0x80)) & ~1) | 4;
    }
    else if (D_800AE858 == 0)
    {
        func_80038A8C((u8)(temp_v1 + 7));
        D_800AE858 = 4;
    }
}
