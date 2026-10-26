#include "common.h"

s32 osPiGetCmdQueue();
s32 osSendMesg();
s32 osJamMesg();
extern s32 D_800A2540;

s32 osPiStartDma(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s16 v;

    if (D_800A2540 == 0) {
        return -1;
    }
    v = 0xC;
    if (arg2 == 0) {
        v = 0xB;
    }
    *(s16 *)arg0 = v;
    *(s8 *)(arg0 + 2) = arg1;
    *(s32 *)(arg0 + 4) = arg6;
    *(s32 *)(arg0 + 8) = arg4;
    *(s32 *)(arg0 + 0xC) = arg3;
    *(s32 *)(arg0 + 0x10) = arg5;
    *(s32 *)(arg0 + 0x14) = 0;
    if (arg1 != 1) {
        return osSendMesg(osPiGetCmdQueue(arg4), arg0, 0);
    }
    return osJamMesg(osPiGetCmdQueue(arg4), arg0, 0);
}
