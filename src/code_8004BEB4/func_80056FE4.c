#include "common.h"

extern int D_800B55F0; void func_80056F8C(int a, int b);
void func_80056FE4(int *arg0) { D_800B55F0 = arg0[0]; func_80056F8C(0, ((unsigned short *)arg0)[2] - 1); }
