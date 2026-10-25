#include "common.h"

extern u8 D_800C02AE[];

u8 func_80055738(s32 arg0) {
    u8 *temp_a1;
    u8 var_t0;
    u16 var_a2;

    var_t0 = 0;
    var_a2 = 0;
    do {
        temp_a1 = *(u8 **) (D_800C02AE + 0x3902 + var_a2 * 4);
        if (temp_a1 != NULL) {
            if (*(s32 *) (temp_a1 + 4) == arg0) {
                var_t0 = 1;
            }
        }
        var_a2 += 1;
    } while ((var_t0 == 0) && (var_a2 < 0x800));
    if (var_t0 != 0) {
        temp_a1[2] = temp_a1[2] - 1;
    }
    return temp_a1[2];
}
