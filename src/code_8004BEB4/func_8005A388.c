#include "common.h"

int func_800592AC(int a); void func_80098290(char *a, int b); void func_800595EC(char *a);
int func_8005A388(int arg0, int arg1) { char buf[16]; func_80098290(buf, func_800592AC(arg1) + 0x30); func_800595EC(buf); return 0; }
