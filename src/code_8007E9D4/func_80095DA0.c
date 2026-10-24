#include "common.h"

unsigned short func_80095DA0(unsigned char *arg0, int arg1) { int i; unsigned int s = 0; for (i = 0; i < arg1; i++) { s += *arg0++; } return s; }
