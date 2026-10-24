#include "common.h"

unsigned int func_80095980(void);
int func_8008DF60(int *arg0) { unsigned int v = func_80095980(); int b = v >> 8; b &= 1; if (v & 0x80) { arg0[1] = (arg0[1] | b) & ~2; } return b; }
