#include "common.h"

extern char *D_800C35A0; void func_800592F4(int a, int b);
int func_800601B4(int arg0) { char *p = D_800C35A0; unsigned short v = *(unsigned short *)(p + 0x2C); int on; if (v & 2) { *(unsigned short *)(p + 0x2C) = v & 0xFFFD; on = 0; } else { *(unsigned short *)(p + 0x2C) = v | 2; on = 1; } func_800592F4(arg0, on); return 0; }
