#include "common.h"

void func_8000DBC0(int a);
void func_8000DF74(char *arg0) { char *p = arg0; if (*(int *)(p + 0x24)) { int t = *(int *)(p + 0x20); *(int *)(p + 0x20) = *(int *)(p + 0x24); *(int *)(p + 0x24) = t; } func_8000DBC0(*(int *)(p + 0x20)); }
