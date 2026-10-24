#include "common.h"

void func_800067FC(char *arg0, unsigned short arg1, short arg2, short arg3) { int o = arg1 << 4; *(short *)(o + *(int *)(arg0 + 0x70)) = arg2; *(short *)(o + *(int *)(arg0 + 0x70) + 2) = arg3; *(short *)(o + *(int *)(arg0 + 0x70) + 4) = 0; }
