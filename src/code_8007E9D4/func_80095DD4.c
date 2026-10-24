#include "common.h"

int func_80095DD4(unsigned short *arg0, unsigned short *arg1, unsigned short *arg2) { unsigned short *p = arg0; unsigned short *end = arg0 + 14; *arg2 = 0; *arg1 = 0; do { unsigned short t = *p; *arg1 += t; p++; *arg2 += ~t; } while (p < end); return 0; }
