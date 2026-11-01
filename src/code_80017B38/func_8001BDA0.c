#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern char D_800AE850[];
extern void *D_800C8054;
s32 func_8001BCE0(s32);
void func_8001BD44(void);
void func_8001BDA0(void)
{
  s32 *p = (s32 *) (D_800AE850 + 0x87D8);
  s32 v;
  *p = func_8001BCE0(0x12C);
  v = func_8001BCE0(0x12C);
  p[2] = p[0];
  *((s32 *) (D_800AE850 + 0x6D9C)) = (s32)D_800C8054;
  p[4] = 0;
  p[5] = 0x12C;
  p[1] = v;
  p[3] = v;
  D_800C8054 = func_8001BD44;
}
