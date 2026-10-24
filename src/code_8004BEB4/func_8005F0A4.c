#include "common.h"

extern float D_800C35E0; void func_8005F014(int a, float *b); void func_80086DE8(int a);
int func_8005F0A4(int arg0) { float *p = &D_800C35E0; func_8005F014(arg0, p); func_80086DE8((int)(*p * 112.0f)); return 0; }
