#include "common.h"

extern int D_800D0658;
extern void *D_800A1468;
extern char D_800A5F9C[];
extern char D_800A5FAC[];
s32 func_80034FF0();
s32 func_8007A794();
s32 func_80081540();
s32 func_800980D0();

void func_8007A6D0(void)
{
    char buf[16];
    char *p;
    u8 i;
    char *src;

    func_8007A794();
    func_80081540(D_800A5F9C);
    src = (char *)(D_800D0658 + *((u8 *)((char *)D_800A1468 + 0x237)) * 0x2C4);
    i = 0;
    do
    {
        buf[i] = src[i];
        i++;
    } while (i < 5);
    p = buf;
    p[i] = 0;
    func_800980D0(p, D_800A5FAC);
    *((s32 *)((char *)D_800A1468 + 0x1E4)) = func_80034FF0(p, 0);
}
