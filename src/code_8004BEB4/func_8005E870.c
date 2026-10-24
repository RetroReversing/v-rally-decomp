#include "common.h"

extern char *D_800C35A0; void func_800592F4(int a, int b);
int func_8005E870(int arg0) { char *p = D_800C35A0; unsigned short n = *(unsigned short *)(p + 0xE); if (n >= 2) { n--; *(unsigned short *)(p + 0xE) = n; func_800592F4(arg0, n - 1); } return 0; }
