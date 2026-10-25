#include "common.h"

extern u16 D_800A1D00[];
s32 func_8008DAF0(s32 arg0)
{
  short a1;
  s32 idx;
  u16 v;
  int new_var;
  a1 = ((u16) arg0) >> 4;
  if (a1 & 0x400)
  {
    idx = (new_var = (~a1) & 0x3FF);
  }
  else
  {
    idx = a1 & 0x3FF;
  }
  v = D_800A1D00[idx];
  if (a1 & 0x800)
  {
    return (s16) (-v);
  }
  return (s16) v;
}
