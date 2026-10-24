#include "common.h"

struct S { char pad[12]; int x; };
extern struct S *D_800A1468;
void func_8005A744(int a, int b);
void func_800592AC(int arg0) { func_8005A744(arg0, D_800A1468->x); }
