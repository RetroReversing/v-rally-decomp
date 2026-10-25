#include "common.h"

s32 func_800592F4(s32, s32);
extern char D_800C02AE[];

s32 func_8005F188(s32 arg0)
{
    u16 *p;
    u16 v;

    p = *(u16 **)(D_800C02AE + 0x32F2);
    v = p[9];
    p[9] = (v & 1) ? (v & 0xFFFE) : (v | 1);
    func_800592F4(arg0, (*(u16 **)(D_800C02AE + 0x32F2))[9] & 1);
    return 0;
}
