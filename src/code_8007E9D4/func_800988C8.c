#include "snapshot31_manual_verified.h"

extern u8 D_800B6FF0[];
extern u8 *D_800ADF00;
extern s64 func_8009A2B0(s64, s64);
extern s64 func_8009A2D0(s64, s64);
u8 *func_800988C8(s64 x, s32 c)
{
  u8 *p = D_800B6FF0;
  s64 new_var;
  union 
  {
    s64 q;
    struct 
    {
      s32 hi;
      u32 lo;
    } w;
  } y;
  s32 h = c >> 31;
  vu32 r;
  do
  {
    {
      y.w.lo = c;
      new_var = x;
      y.w.hi = h;
      r = (s32) func_8009A2D0(x, (s64)c);
      p--;
    }
    *p = D_800ADF00[r];
    x = func_8009A2B0(x, (s64)c);
  }
  while (x != 0);
  return p;
}
