#include "common.h"

int func_80094580(char *arg0, int arg1, int arg2) { char *q = *(char **)(arg0 + 0x1C); if (arg1 == 2) { int n = *(int *)(arg0 + 0x14); *(int *)(arg0 + 0x14) = n + 1; ((int *)q)[n] = arg2; } return 0; }
