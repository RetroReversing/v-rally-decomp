#include "common.h"

extern int D_800C35B8; extern char D_800C02AE[];
int func_80009FE4(void) { int i = D_800C35B8; int *p = (int *)(D_800C02AE + 0x3302) + i; int old = *p; *p = old + 0x18; return old; }
