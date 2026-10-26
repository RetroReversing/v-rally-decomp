#include "common.h"

u64 osGetTime(void);
u64 func_8009A2B0(u64, u64);
extern char *D_800C7304;

void func_80013F3C(void)
{
    char *s1;
    char *s0;
    u32 idx;
    u64 t;
    u64 r;

    if (*(u32 *)(D_800C7304 + 4) < 4) {
        t = osGetTime();
        s1 = D_800C7304;
        idx = *(u32 *)(s1 + 4);
        s0 = (char *) (idx * 8);
        s0 = s1 + (u32) s0;
        r = func_8009A2B0(t << 6, 3000);
        r = r - *(u64 *)(s1 + 8);
        *(u64 *)(s0 + 0xD0) = r;
    }
}
