#include "common.h"

extern s32 D_800A1B70;
static inline s8 *inline_fn(s8 *arg0, int arg1)
{
  return arg0 + arg1;
}

s32 func_800857C0(s32 arg0)
{
  s32 new_var;
  int new_var2;
  new_var = D_800A1B70;
  new_var2 = (arg0 & 0xFF) * 0x18;
  return (*((s32 *) inline_fn((s8 *) (new_var + new_var2), 0x330))) == 1;
}
