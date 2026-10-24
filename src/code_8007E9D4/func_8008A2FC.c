#include "common.h"

void func_8008A2FC(char *arg0, int arg1, int arg2) { unsigned int i = arg1 & 0xFFFF; int *p = *(int **)(arg0 + 0x10); p[i * 5] = arg2; }
