#include "common.h"

extern u8 D_800C02AE[];
extern u8 D_800A1468[];
extern u8 *D_800D0634[];
s32 func_8005946C(s32, u16);

s32 func_80065DD0(s32 arg0) {
    u8 *var_v1;
    u16 var_a1;
    s32 var_v0;

    var_v1 = *(u8 **) (D_800C02AE + 0x32F2);
    var_a1 = *(u16 *) (var_v1 + 0x22);
    var_v0 = *(u16 *) (D_800D0634[*(u8 *) (*(u8 **) D_800A1468 + 0x23C)] + 0x14) - 1;
    if (var_a1 >= var_v0) {
        *(u16 *) (var_v1 + 0x22) = 0;
    } else {
        *(u16 *) (var_v1 + 0x22) = var_a1 + 1;
    }
    func_8005946C(arg0, *(u16 *) (*(u8 **) (D_800C02AE + 0x32F2) + 0x22));
    return 1;
}
