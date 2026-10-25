#include "common.h"

s32 func_8008E118(u8 *);
u8 *func_80098370(u8 *arg0, u8 *arg1, s32 arg2)
{
  u8 *dst;
  u8 *src;
  s32 n;
  u8 c;
  u8 d;
  src = arg1;
  n = arg2;
  if (n == 0)
  {
    return arg0;
  }
  dst = arg0 + func_8008E118(arg0);
  c = (*(dst++) = *(src++));
  if (c != 0)
  {
    while (c != 0)
    {
      n--;
      if (n == 0)
      {
        *dst = 0;
        break;
      }
      d = *(src++);
      *(dst++) = d;
      c = d;
    }

  }
  return arg0;
}
