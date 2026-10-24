#include "common.h"

extern unsigned int D_800A58C8[];
unsigned int func_8006F890(unsigned char *arg0, int arg1) { unsigned int c = 0xFFFFFFFF; while (arg1--) { c = D_800A58C8[(*arg0++ ^ c) & 0xFF] ^ (c >> 8); } return c; }
