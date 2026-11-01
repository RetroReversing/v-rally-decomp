#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern char D_800A73E0[];
extern char D_800AE850[];
extern void *D_800C8054;
s32 func_80009E10(s32);
void func_80009E7C(void);
void func_80009ED8(void)
{
  int new_var3;
  s32 *new_var2;
  s32 *p = (s32 *) (D_800A73E0 + 0x6BA8);
  s32 v;
  unsigned short new_var;
  s32 a;
  s32 b;
  new_var3 = 0x15E;
  *p = func_80009E10(new_var3);
  v = func_80009E10(new_var3);
  a = p[0];
  b = *(&D_800C8054);
  do
  {
    p[1] = v;
    p[4] = 0;
    new_var = 5;
    p[3] = v;
    p[5] = new_var3;
    D_800C8054 = func_80009E7C;
  }
  while (0);
  p[2] = a;
  do
  {
  }
  while (0);
  *(new_var2 = (s32 *) (D_800AE850 + 0x11F4)) = b;
}
