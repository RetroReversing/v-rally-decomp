#include "common.h"

extern s32 D_800A1CF0;
extern char D_800AB990[];
extern char D_800D05C0[];
extern char D_800D05C1[];

void func_8008D8B4(void)
{
    s32 sp10;

    if (D_800A1CF0 == 0) {
        D_800A1CF0 = 1;
        osCreateMesgQueue(D_800D05C0, D_800AB990, 1);
        osSendMesg((D_800D05C1-1), 0, 0);
    }
    osRecvMesg(D_800D05C0, &sp10, 1);
}
