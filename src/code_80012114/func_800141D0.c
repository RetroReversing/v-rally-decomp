#include "common.h"

extern s32 (*D_8009BB14)();
extern u32 *D_800C7304;
u64 osGetTime();
u64 func_8009A2B0(u64 a, u64 b);

void func_800141D0(void *arg0)
{
    u32 *s1;
    u8 *s0;
    u64 x;
    u64 r;

    D_8009BB14();
    if (arg0 != NULL && *(u16 *)((u8 *)arg0 + 0x48) != 4 && *D_800C7304 < 8) {
        x = osGetTime();
        s1 = D_800C7304;
        s0 = (u8 *)(s1[0] * 8 + (u32)s1);
        r = func_8009A2B0(x << 6, 0xBB8);
        r = r - *(u64 *)(s1 + 2);
        *(u64 *)(s0 + 0x90) = r;
    }
}
