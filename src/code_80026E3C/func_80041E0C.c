#include "common.h"

extern char D_800AE850[];
extern char D_800C02AE[];

s32 func_80022184();
s32 func_800221D4();
s32 func_80080440();
extern s32 func_80041E6C;

s32 func_80041E0C(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7338;
    if (func_80022184(temp_s0) == 0) {
        *((s32 *)(D_800AE850 + 0x72FC)) = func_80080440();
        func_800221D4(temp_s0, &func_80041E6C);
        *((s32 *)(D_800C02AE + 0x3312)) = 0;
        return 1;
    }
    return 0;
}
