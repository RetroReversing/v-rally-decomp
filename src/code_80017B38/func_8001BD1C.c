#include "common.h"

extern int D_800B7038; extern char D_800AE850[];
int func_8001BD1C(void) { int i = D_800B7038; int *p = (int *)(D_800AE850 + 0x87E0) + i; int old = *p; *p = old + 0x40; return old; }
