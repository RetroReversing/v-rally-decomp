#include "common.h"

extern char D_8009BF38[];
extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_8007EE9C();
void func_80081B28();

void func_80015B9C(s32 arg0, char *arg1, s32 arg2)
{
    s32 pad[2];
    char *s0;
    u32 i;
    char *a0;
    char *s3;
    u32 count;

    s3 = arg1;
    s0 = s3 + 0x24;
    count = *(u32 *)(arg1 + 0x20);
    i = 0;
    a0 = NULL;
    *(char **)(D_800AE850 + 0x6E9C) = arg1;
    *(char **)(D_800C02AE + 0x7CD2) = arg1;
    if (count != 0)
    {
        do
        {
            a0 = ((char *(*)(void *, s32, s32)) * (void **)(D_8009BF38 + (*(u16 *)(s0 + 6) << 2)))(s0, arg0, arg2);
            s0 += 8;
            i++;
        } while (i < *(u32 *)(s3 + 0x20));
    }
    if (*(u16 *)(a0 + 0x2C) == 1)
    {
        func_80081B28(arg1);
    }
    func_8007EE9C(*(void **)(D_800AE850 + 0x1210));
}
