#include "common.h"

extern u8 D_8009BBBC;
extern char D_800C02AE[];
void *func_800801D0(s32 a0, s32 a1);
void func_8001B8CC(s32 arg0)
{
  u32 v;
  u32 lim;
  u32 i;
  u8 *base;
  u8 *p;
  base = *((u8 **) (D_800C02AE + 0x32F2));
  if (D_8009BBBC == 0)
  {
    v = base[0xF];
  }
  else
  {
    v = 1;
  }
  v &= 0xFF;
  if (v != 0)
  {
    lim = v;
    i = 1;
    do
    {
      p = func_800801D0(arg0, 0x24);
      *((s32 *) (p + 0x14)) = 0;
      *((s16 *) (p + 0x18)) = 1;
      *((s16 *) (p + 0x1C)) = (v = 0);
      *((s16 *) (p + 0x1A)) = 0;
      *((s16 *) (p + 0x1E)) = -1;
      *((s16 *) (0x20 + p)) = -1;
      i++;
    }
    while (((unsigned short) lim) >= i);
  }
}
