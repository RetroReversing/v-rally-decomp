#include "common.h"

extern short D_800D061E[];
void func_8001D954(char *arg0) { int i = 1; short *p = D_800D061E; arg0 += 0x4C; do { *p = *(int *)(arg0 + 0x44); arg0 += 0x4C; i++; p++; } while (i < 0xB); }
