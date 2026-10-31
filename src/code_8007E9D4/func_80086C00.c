#include "snapshot31_verified.h"

#define func_800898D0 ((s32 (*)(u8 *, s32, s32, s32, s32))func_800898D0)
extern s32 *D_800A9930;
extern u8 *D_800B68F0;
extern s32 D_800C782C;
s32 func_80086C00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
  s32 best;
  s32 new_var;
  s32 min;
  s32 i;
  s32 limit;
  u8 *new_var2;
  s32 spare[4];
  u8 *p;
  u8 *selected;
  u8 *new_var3;
  u8 *new_var4;
  s32 val;
  s32 count;
  best = arg4;
  if (best == (-1))
  {
    best = D_800A9930[arg0];
  }
  min = best + 1;
  if (arg3)
  {
    count = D_800C782C;
    p = D_800B68F0;
    i = 0;
    new_var2 = p + 0x9e;
    if (count > 0)
    {
      limit = count;
      do
      {
        min = *((u16 *) (p + 0x9e));
        if ((u16)min == arg0)
        {
          goto found;
        }
        i++;
        p += 0x134;
      }
      while (i < limit);
      min = best + 1;
    }
  }
  count = D_800C782C;
  p = D_800B68F0;
  i = 0;
  if (count > 0)
  {
    limit = count;
    new_var = limit;
    do
    {
      count = *((s32 *) p);
      if (!count)
      {
        goto found;
      }
      if ((*((u16 *) (p + 0x9e))) != 0)
      {
        val = *((s32 *) (p + 0x44));
        if (val < min)
        {
          min = val;
          selected = p;
        }
      }
      i++;
      p += 0x134;
    }
    while (i < new_var);
  }
  if (min >= best)
  {
 do { return 0; found: return func_800898D0(p, arg0, arg1, arg2, best); } while (0);
  }
  return func_800898D0(selected, arg0, arg1, arg2, best);
  new_var4 = p;
}
