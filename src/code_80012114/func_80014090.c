#include "common.h"

u64 osGetTime();
u64 func_8009A2B0();
extern void (*D_8009BB20)();
extern u8 *D_800C7304;

void func_80014090(void)
{
    u64 temp_ret;
    u64 temp_ret_2;
    u64 temp_a1;
    u8 *temp_s1;
    u8 *temp_s0;

    D_8009BB20();
    if (*((u32 *) (D_800C7304 + 4)) < 4)
    {
        temp_ret = osGetTime();
        temp_s1 = D_800C7304;
        temp_s0 = (u8 *) ((*((u32 *) (temp_s1 + 4)) << 3) + (u32) temp_s1);
        temp_ret_2 = func_8009A2B0(temp_ret << 6, (u64) 0xBB8);
        temp_a1 = *((u64 *) (temp_s1 + 8));
        *((u64 *) (temp_s0 + 0xD0)) = temp_ret_2 - temp_a1;
    }
}
