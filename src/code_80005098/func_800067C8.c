#include "common.h"

void func_800067C8(char *arg0, unsigned short arg1, short arg2, short arg3, s32 arg4) {
    int o = arg1 << 4;
    *(short *)(o + *(int *)(arg0 + 0x70)) = arg2;
    *(short *)(o + *(int *)(arg0 + 0x70) + 2) = arg3;
    o += *(int *)(arg0 + 0x70);
    *(short *)(o + 4) = ((u16 *)&arg4)[1];
}
