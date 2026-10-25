#include "common.h"

extern char D_800C02AE[];
s32 func_800592F4(s32 a, s32 b, void *c);

s32 func_80062CF0(void)
{
    u32 var_a1;
    void *p;

    p = *(void **)(D_800C02AE + 0x32F2);
    if (*(u16 *)((char *)p + 0xE) == 2) {
        if (*(u16 *)((char *)p + 0x18) != 0) {
            *(u16 *)((char *)p + 0x18) = 0;
            *(u16 *)((char *)p + 0x1A) = 1;
        } else {
            *(u16 *)((char *)p + 0x1A) = 0;
        }
        var_a1 = *(u16 *)((char *)*(void **)(D_800C02AE + 0x32F2) + 0x1A);
        var_a1 = (var_a1 < 1) * 2;
        func_800592F4(3, var_a1, p);
    } else {
        var_a1 = 0;
        *(u16 *)((char *)p + 0x18) = 0;
        *(u16 *)((char *)p + 0x1A) = 1;
        func_800592F4(3, var_a1, p);
    }
    return 0;
}
