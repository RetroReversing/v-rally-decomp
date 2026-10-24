#include "common.h"

extern char *D_800C35A0; void func_800592F4(int a, int b);
int func_8005F258(int arg0) { char *p = D_800C35A0; unsigned short n = *(unsigned short *)(p + 0x16); if (n) { n--; *(unsigned short *)(p + 0x16) = n; func_800592F4(arg0, n); } return 0; }
