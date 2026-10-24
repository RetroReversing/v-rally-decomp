#include "common.h"

int func_8008949C(int a);
unsigned char *func_80088088(char *arg0, unsigned char *arg1) { int v = func_8008949C(*arg1++); arg0[0xB1] = v; v += *arg1; arg0[0xB1] = v; return arg1 + 1; }
