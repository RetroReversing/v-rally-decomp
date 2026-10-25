#include "common.h"

s32 func_80096C10(s32 arg0)
{
  s32 v1;
  u32 a1;
  s32 a0;

  v1 = 0;
  a1 = 0x400;
  a0 = arg0 & 0xFFFF;
  do
  {
    s32 t = a0 & a1;
    v1 <<= 1;
    if (t != 0)
    {
      if (v1 & 0x20)
      {
        v1 ^= 0x14;
      }
      else
      {
        v1 += 1;
      }
    }
    else
    {
      if (v1 & 0x20)
      {
        v1 ^= 0x15;
      }
    }
    a1 >>= 1;
  } while (a1 != 0);
  a1 = 5;
  v1 <<= 1;
  do
  {
    if (v1 & 0x20)
    {
      v1 ^= 0x15;
    }
    a1--;
    if (a1 != 0)
    {
      v1 <<= 1;
    }
  } while (a1 != 0);
  return v1 & 0x1F;
}
