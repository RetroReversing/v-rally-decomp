#include "common.h"

extern char *D_800C35A0; void func_800592F4(int a, int b);
int func_800707D0(int arg0) { char *p = D_800C35A0; int v; if (*(unsigned short *)(p + 0x20) >= 8) { *(unsigned short *)(p + 0x20) = 0; v = 0; } else { *(unsigned short *)(p + 0x20) = 8; v = 1; } func_800592F4(arg0, v); return 0; }
