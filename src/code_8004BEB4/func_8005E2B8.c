#include "common.h"

extern char *D_800C35A0; void func_8005A2F4(int a); void func_8005A474(int a, int b);
int func_8005E2B8(void) { func_8005A2F4(1); func_8005A474(1, 1); *(short *)(D_800C35A0 + 0x22) = 0; return 0; }
