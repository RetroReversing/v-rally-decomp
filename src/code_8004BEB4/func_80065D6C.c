#include "common.h"

extern u8 D_800C02AE[];
extern u8 *D_800A1468;
s32 func_8005946C(s32, u16);

s32 func_80065D6C(s32 arg0)
{
    u8 *temp_v1;
    s32 var_v0;

    temp_v1 = *(u8 **)(D_800C02AE + 0x32F2);
    var_v0 = *(u16 *)(temp_v1 + 0x22);
    if (var_v0 != 0)
    {
        var_v0 -= 1;
    }
    else
    {
        var_v0 = *(u16 *)(*(u8 **)(D_800C02AE + 0x10386 + (D_800A1468[0x23C] << 2)) + 0x14);
        var_v0 -= 1;
    }
    *(vu16 *)(temp_v1 + 0x22) = var_v0;
    func_8005946C(arg0, *(u16 *)(*(u8 **)(D_800C02AE + 0x32F2) + 0x22));
    return 1;
}
