#include "common.h"

unsigned char *func_8008795C(char *arg0, unsigned char *arg1) { unsigned char t = *arg1++; arg0[0xB0] = t; if (t) { *(float *)(arg0 + 0x4C) = *(float *)(arg0 + 0x28); } return arg1; }
