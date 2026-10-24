#include "common.h"

extern int D_800C7410[]; void func_80022F98(int a);
void func_8002305C(void) { register int i = 0; register int *p = D_800C7410; do { func_80022F98(*p); p++; i++; } while (i == 0); }
