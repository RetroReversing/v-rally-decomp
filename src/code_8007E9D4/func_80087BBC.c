#include "common.h"

unsigned char *func_80087BBC(char *arg0, unsigned char *arg1) { unsigned int hi = *arg1++; unsigned int lo = *arg1; *(short *)(arg0 + 0xAC) = 0; *(short *)(arg0 + 0xAA) = lo | (hi << 8); return arg1 + 1; }
