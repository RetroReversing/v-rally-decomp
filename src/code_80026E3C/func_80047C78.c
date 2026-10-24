#include "common.h"

s32 func_80022184();
s32 func_80022200();
s32 func_80047D18();
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80047C78(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7380;
    if (func_80022184(temp_s0) != 0) {
        func_80047D18(*(s32 *)(D_800C02AE + 0x7672));
        func_80022200(temp_s0);
    }
}
