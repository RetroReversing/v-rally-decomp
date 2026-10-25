#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];
extern void *D_800A1468;
s32 func_800592F4(s32 a, s32 b, void *c);
s32 func_80066B88(void);

s32 func_8005E8B0(s32 arg0)
{
    void *p;
    u16 n;
    u16 t;

    p = *(void **)(D_800C02AE + 0x32F2);
    n = *(u16 *)((char *)p + 0xE);
    if ((u32)n < *(u8 *)(D_800AE850 + 0x7D50)) {
        t = n + 1;
        *(u16 *)((char *)p + 0xE) = t;
        func_800592F4(arg0, (t & 0xFFFF) - 1, p);
        func_80066B88();
    } else if ((u32)n < 2) {
        *(s16 *)((char *)D_800A1468 + 0x220) = 0x3C;
    }
    return 0;
}
