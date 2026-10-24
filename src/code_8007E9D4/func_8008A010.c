#include "common.h"

char *func_8008A054(int a, int b);
int func_8008A010(int arg0, int arg1) { int s = arg1 & 0xFFFF; char *v = func_8008A054(arg0, s); return *(int *)(v + 8) + (s - *(unsigned char *)(v + 0xD)) * 0xC; }
