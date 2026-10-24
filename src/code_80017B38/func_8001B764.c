#include "common.h"

void func_8001B764(unsigned char *arg0) { unsigned int c; while ((c = *arg0) != 0) { if (c - 0x41 < 0x1A) { *arg0 = c + 0x20; } arg0++; } }
