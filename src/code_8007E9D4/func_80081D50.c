#include "common.h"

extern char D_800C02AE[];
int func_8007EAA0(int a, int b);
int func_80081D50(int arg0) { int t = func_8007EAA0(arg0, *(int *)(D_800C02AE + 0x30C2)); *(int *)(D_800C02AE + 0x30EA) = t; *(int *)(D_800C02AE + 0x30EE) = t; return 0; }
