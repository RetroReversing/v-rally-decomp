#include "common.h"

char *func_8008A054(int a, int b);
void func_8008A14C(int arg0, int arg1) { func_8008A054(arg0, arg1 & 0xFFFF)[0xE] = arg1; }
