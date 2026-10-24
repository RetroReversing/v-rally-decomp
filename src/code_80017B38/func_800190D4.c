#include "common.h"

void func_80019094(char *a);
void func_800190D4(char *arg0) { char *p = *(char **)arg0; int i; for (i = 0; i < *(unsigned short *)(arg0 + 4); i++) { func_80019094(p); p += 0x18; } }
