#include "common.h"

extern char D_8009EB84[]; extern int D_8009EB80;
void func_800334F4(char *arg0) { int o = D_8009EB80 * 0x18; *(int *)(D_8009EB84 + o) = *(int *)(arg0 + 0x90); *(int *)(D_8009EB84 + 4 + o) = *(int *)(arg0 + 0xDC); *(int *)(D_8009EB84 + 8 + o) = *(int *)(arg0 + 0x128); *(int *)(D_8009EB84 + 0xC + o) = *(int *)(arg0 + 0x174); }
