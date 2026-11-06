#include "decompdecomp_tail_dispatch.h"
#line 1 "func.c"
extern unsigned long long func_8009A074(unsigned long long,unsigned long long);
extern unsigned long long func_80099F78(unsigned long long,unsigned long long);
unsigned long long func_8009A2B0(unsigned long long n,unsigned long long d) { if (d >> 32) return func_80099F78(n,d); return func_8009A074(n,d); }
