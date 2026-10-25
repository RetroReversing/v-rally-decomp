#include "common.h"

s32 func_800592F4();
extern char D_800C02AE[];

s32 func_80062D6C(void)
{
    u16 *p;
    s32 a0;
    s32 a1;

    p = *(u16 **)(D_800C02AE + 0x32F2);
    if (p[7] == 2)
    {
        if (p[0xC] != 0)
            return 0;
        a0 = 3;
        if (p[0xD] != 0)
        {
            p[0xC] = 1;
            a1 = 1;
        }
        else
        {
            p[0xD] = 1;
            a1 = 0;
        }
    }
    else if (p[7] == 1)
    {
        a0 = 3;
        a1 = 1;
        p[0xC] = 1;
        p[0xD] = 1;
    }
    else
        return 0;
    func_800592F4(a0, a1);
    return 0;
}
