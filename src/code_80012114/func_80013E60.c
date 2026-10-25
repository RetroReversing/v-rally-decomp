#include "common.h"

u64 func_8009A2B0(u64, u64);
extern char D_800AE850[];

s32 func_80013E60(void)
{
    char *p;

    p = *(char **)(D_800AE850 + 0x7FCC);
    p += *(s32 *)p * 8;
    return (s32)func_8009A2B0(*(u64 *)(p + 0x48), 0xFA) + 0x28;
}
