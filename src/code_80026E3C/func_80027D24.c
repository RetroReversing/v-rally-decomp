#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];

s32 func_80027D24(u32 arg0, u32 arg1) {
    u8 var_a0;
    u8 temp_v1;

    var_a0 = arg0 + (((arg1 - arg0) * 0x1E) >> 7);
    if (var_a0 < 2) {
        return 0;
    }
    temp_v1 = D_800AE850[0x18B4 + *(u16 *) (*(char **) (D_800C02AE + 0x32F2) + 0x16)];
    if (temp_v1 < var_a0) {
        var_a0 = temp_v1;
    }
    return var_a0;
}
