#include "common.h"

extern void (*D_8009BB1C)(void);
extern u32 *D_800C7304;
u64 func_8008BA60(void);
u64 func_8009A2B0(u64, u64);

void func_80014130(void)
{
    u32 *s1;
    u32 *s0;
    u64 r;

    D_8009BB1C();
    if (D_800C7304[0] < 4)
    {
        r = func_8008BA60();
        s1 = D_800C7304;
        s0 = (u32 *) (s1[0] * 8 + (u32) s1);
        r = func_8009A2B0(r << 6, 3000);
        r = r - *(u64 *)(s1 + 2);
        *(u64 *)(s0 + 4) = r;
    }
}
