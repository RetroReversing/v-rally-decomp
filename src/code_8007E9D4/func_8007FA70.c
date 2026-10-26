#include "common.h"

s32 func_8007F4E4();
s32 osCreateMesgQueue();
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8007FC14;

s32 func_8007FA70(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x1D10;
    *(s32 * *)(D_800C02AE + 0x7DFA) = &func_8007FC14;
    *(s32 *)(D_800AE850 + 0x2268) = 0;
    *(s32 *)(D_800AE850 + 0x226C) = 0;
    *(s32 *)(D_800AE850 + 0x2270) = 0;
    *(s32 *)(D_800AE850 + 0x2274) = 0;
    osCreateMesgQueue(temp_s0 + 0x10, temp_s0 + 0x28, 8);
    *(s32 *)(D_800AE850 + 0x1D10) = func_8007F4E4(4, 0, 8);
    *(s32 *)(D_800AE850 + 0x1D14) = func_8007F4E4(9, 1, 0x10);
    *(s32 *)(D_800AE850 + 0x1D18) = func_8007F4E4(0x26, 0, 8);
    *(s32 *)(D_800AE850 + 0x1D1C) = func_8007F4E4(0x22, 0, 8);
    return 1;
}
