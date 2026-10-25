#include "common.h"

s32 func_80094820(s32);

s32 func_8008F1A0(s32 arg0)
{
  if ((u32) (arg0 - 0x80000000) > 0x1FFFFFFFU)
  {
    if ((u32) (arg0 + 0x60000000) > 0x1FFFFFFFU)
    {
      return func_80094820(arg0);
    }
    return arg0 & 0x1FFFFFFF;
  }
  return arg0 & 0x1FFFFFFF;
}
