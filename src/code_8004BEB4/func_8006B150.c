#include "common.h"

s32 func_800592F4();
s32 func_8006204C();
extern char *D_800A1468;
extern char D_800C02AE[];

s32 func_8006B150(s32 arg0)
{
    char *p;
    char *s0;
    s16 temp_v0;
    s16 temp_a0;
    char *temp_a2;

    p = *(char **)(D_800C02AE + 0x32F2);
    s0 = p + ((*(u8 *)(p + *(s8 *)(D_800A1468 + 0x228) + 0x32) * 40) + 0x44);
    temp_a2 = (char *)(((func_8006204C(*(u8 *)(p + 0x1F), *(u8 *)(p + 0x21), *(u8 *)(p + 0x23)) & 0xFF) * 2) + (u32)s0);
    temp_v0 = *(s16 *)(temp_a2 + 0x1C);
    if (temp_v0 >= -0x13)
    {
        temp_a0 = temp_v0 - 0xA;
        *(s16 *)(temp_a2 + 0x1C) = temp_a0;
        func_800592F4(arg0, -(temp_a0 / 10) + 2, temp_a2);
    }
    return 1;
}
