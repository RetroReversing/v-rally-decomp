#include "common.h"

void func_8002F9C8(char *arg0, int arg1) { int var_a1 = arg1; int var_v0; char *var_a0 = arg0; var_v0 = var_a1; goto loop_2; block_1: *(short *)var_a0 = 0; var_a0 += 0x24; var_v0 = var_a1; loop_2: var_a1 -= 1; if (var_v0 != 0) goto block_1; return; }
