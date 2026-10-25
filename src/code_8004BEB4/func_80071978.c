#include "common.h"

s32 func_8005946C();
extern char D_800C02AE[];

s32 func_80071978(s32 arg0)
{
    if (*((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)) >= *((u16 *)(*((char **)(D_800C02AE + 0x10386 + *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x1E)) * 4)) + *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x20)) * 0x2C4 + 0x14)) - 1)
    {
        *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)) = 0;
    }
    else
    {
        *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)) = *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)) + 1;
    }

    func_8005946C(arg0, *((u16 *)(*((char **)(D_800C02AE + 0x32F2)) + 0x22)));
    return 0;
}
