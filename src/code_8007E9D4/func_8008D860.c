#include "common.h"

s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800A1CF0;
extern char D_800A73E0[];
extern char D_800C02AE[];

void func_8008D860(void) {
    void *temp_s0;

    temp_s0 = D_800C02AE + 0x10312;
    D_800A1CF0 = 1;
    osCreateMesgQueue(temp_s0, D_800A73E0 + 0x45B0, 1);
    osSendMesg(temp_s0, 0, 0);
}
