#include "common.h"

unsigned char *func_8008792C(char *arg0, unsigned char *arg1) { unsigned int a = *arg1++; if (a & 0x80) { unsigned int b = *arg1++; a = b | ((a & 0x7F) << 8); } *(short *)(arg0 + 0xA6) = a; return arg1; }
