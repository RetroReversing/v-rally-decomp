#include "common.h"

s32 osCreateMesgQueue();
s32 osSendMesg();
extern s32 D_800A39A0;
extern char D_800A73E0[];
extern char D_800AE850[];

void func_80094660(void) {
    void *temp_s0;

    temp_s0 = D_800AE850 + 0x87A8;
    D_800A39A0 = 1;
    osCreateMesgQueue(temp_s0, D_800A73E0 + 0x6AF0, 1);
    osSendMesg(temp_s0, 0, 0);
}
