#include "common.h"

extern char *D_800A1234;
extern char *D_800A1238;
extern char D_800C02AE[];

void func_80050AB8(s32 arg0)
{
    u8 var_v0;
    u8 var_v1;
    char *temp_a1;
    char *temp_a2;

    temp_a1 = D_800A1238;
    temp_a2 = D_800A1234;
    temp_a1[0x114] = 0;
    temp_a2[0x114] = 0;
    var_v0 = arg0;
    if (*((u16 *) (*((char **) (D_800C02AE + 0x32F2)) + 0x1A)) == 1) {
        var_v1 = arg0;
        temp_a1 = temp_a1 + (var_v1 * 0x44);
        *((u16 *) (temp_a1 + 0xA)) = 4;
        *((u16 *) (temp_a1 + 0xC)) = 0;
        *((u16 *) (temp_a1 + 0x8)) &= 0xFBFF;
        var_v0 = arg0;
    }
    temp_a1 = temp_a2 + (var_v0 * 0x44);
    *((u16 *) (temp_a1 + 0xC)) = 0;
    *((u16 *) (temp_a1 + 0xA)) = 1;
}
