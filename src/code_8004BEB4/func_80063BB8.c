#include "common.h"

s32 func_800593FC();
s32 func_8005946C();
s32 func_8005A00C();
s32 func_8005A6BC();
extern void *D_800A1468;
extern char D_800C02AE[];

s32 func_80063BB8(s32 arg0) {
    s32 var_a1;
    s32 var_s0;

    var_s0 = arg0;
    ((s8 *) D_800A1468)[0x245] = 1;
    ((u16 *) *(void **) (D_800C02AE + 0x32F2))[0x22 / 2] = 0;
    if (((s16 *) *(void **) (D_800C02AE + 0x325A))[1] == 2) {
        var_a1 = 0x17;
    } else {
        func_8005A00C(0);
        func_8005A6BC(0x13);
        func_8005A6BC(0x14);
        func_8005A6BC(0x15);
        func_8005A6BC(0x16);
        var_s0 = arg0;
        var_a1 = 0xE;
    }
    func_800593FC(var_s0, var_a1);
    func_8005946C(arg0, ((u16 *) *(void **) (D_800C02AE + 0x32F2))[0x22 / 2]);
    return 0;
}
