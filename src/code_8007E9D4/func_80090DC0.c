#include "snapshot29_0433f7af8f6d.h"

extern vu32 D_A4800000;

s32 func_80090DC0(s32 arg0, s32 arg1) {
    if ((*(vu32 *)0xA4800018) & 3) {
        return -1;
    }
    if (arg0 == 1) {
        osWritebackDCache(arg1, 0x40);
    }
    *(vu32 *)0xA4800000 = osVirtualToPhysical(arg1);
    if (arg0 == 0) {
        *(vu32 *)0xA4800004 = 0x1FC007C0;
    } else {
        *(vu32 *)0xA4800010 = 0x1FC007C0;
    }
    if (arg0 == 0) {
        osInvalDCache(arg1, 0x40);
    }
    return 0;
}
