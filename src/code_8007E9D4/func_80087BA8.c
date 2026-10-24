#include "common.h"

unsigned char *func_80087BA8(char *arg0, unsigned char *arg1) { unsigned char t = *arg1; *(short *)(arg0 + 0xAA) = 0; *(short *)(arg0 + 0xAC) = t; return arg1 + 1; }
