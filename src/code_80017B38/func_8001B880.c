#include "common.h"

s32 func_80015B00();
s32 func_80022184();
s32 func_80022200();
extern s8 D_8009CED4;
extern char D_800AE850[];

void func_8001B880(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x7368;
    if (func_80022184(temp_s0) != 0) {
        func_80015B00();
        func_80022200(temp_s0);
        D_8009CED4 = 0;
    }
}
