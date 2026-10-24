#include "common.h"

void func_80006230(char *a);
void func_800061FC(char *arg0, int arg1) { int *p = *(int **)(arg0 + 0x14); *(int **)(arg0 + 0x14) = p + 2; p[0] = 0xDA380007; p[1] = arg1; func_80006230(arg0); }
