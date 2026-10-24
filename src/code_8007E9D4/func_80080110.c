#include "common.h"

void func_80080110(int *arg0, int *arg1) { if (arg1[0] == 0) { arg1[0] = (int)arg0; } else { *(int *)(arg1[1] + 4) = (int)arg0; } arg0[1] = 0; { int t = arg1[1]; *(short *)(arg0 + 2) = 0; *(short *)((char *)arg0 + 10) = 0; arg0[0] = t; } arg1[1] = (int)arg0; }
