#include "common.h"

void func_80005FE8(s32, s32, s32);
extern s32 D_8009B5A4;
extern char D_800AE850[];

void func_80005428(s32 arg0, ...)
{
    s32 args[10];
    char *ap;
    u8 i;
    u8 j;
    s32 val;

    args[0] = arg0;
    ap = (char *)__builtin_next_arg(arg0);
    for (i = 1; i < 10; i++)
    {
        args[i] = 0;
        val = *(s32 *)((u32)(ap + 3) & ~3);
        ap = (char *)(((u32)(ap + 3) & ~3) + 4);
        args[i] = val;
        if (val == 0)
        {
            break;
        }
    }
    for (j = 0; j < i; j++)
    {
        func_80005FE8(*(s32 *)(D_800AE850 + 0x7400), D_8009B5A4, args[j]);
    }
}
