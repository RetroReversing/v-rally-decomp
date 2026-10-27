#include "common.h"

static inline int inline_fn(s32 arg0)
{
  return arg0 + 0xFFF;
}

static inline int inline_fn2(s16 arg0, s32 arg1)
{
  return arg0 * arg1;
}

void func_8002D3AC(s16 *arg0, s16 *arg1, s32 arg2, s32 arg3, s16 *arg4)
{
  s32 v;
  s32 x;
  v = arg0[0] * arg2; v += arg1[0] * arg3;
  if (v >= 0)
  {
    x = v;
  }
  else
  {
    x = inline_fn(v);
  }
  v = x >> 12;
  arg4[0] = v;
  v = arg0[1] * arg2; v += arg1[1] * arg3;
  if (v >= 0)
  {
    x = v;
  }
  else
  {
    x = inline_fn(v);
  }
  v = x >> 12;
  arg4[1] = v;
  v = arg0[2] * arg2; arg2=v; arg2 += arg1[2] * arg3;
  if (arg2 >= 0)
  {
    x = arg2;
  }
  else
  {
    x = inline_fn(arg2);
  }
  arg2 = x >> 12;
  arg4[2] = arg2;
}
