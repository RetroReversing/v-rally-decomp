#include "common.h"

s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osSendMesg();
extern s32 D_800A39A0;
extern char D_800A73E0[];
extern char D_800AE850[];
extern char D_800B6FF8[];

void func_800946B4(void)
{
    s32 sp10;

    if (D_800A39A0 == 0) {
        D_800A39A0 = 1;
        osCreateMesgQueue(D_800AE850 + 0x87A8, D_800A73E0 + 0x6AF0, 1);
        osSendMesg(D_800B6FF8, 0, 0);
    }
    osRecvMesg(D_800AE850 + 0x87A8, &sp10, 1);
}
