#include "common.h"

char *func_8008A010(int a, int b);
void func_8008A0D8(int arg0, int arg1, char arg2) { func_8008A010(arg0, arg1 & 0xFFFF)[9] = arg2; }
