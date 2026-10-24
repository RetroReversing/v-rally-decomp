#include "common.h"

char *func_8008A010(int a, int b);
void func_8008A104(int arg0, int arg1, char arg2, char arg3) { char *t = func_8008A010(arg0, arg1 & 0xFFFF); t[9] = arg2; t[0xA] = arg3; }
