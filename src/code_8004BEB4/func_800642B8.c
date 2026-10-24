#include "common.h"

extern char *D_800A1468; void func_800580D0(int a, int b);
int func_800642B8(void) { *(char *)(D_800A1468 + 0x2BD) = 1; func_800580D0(0, 0); *(char *)(D_800A1468 + 0x24D) = 0; return 0; }
