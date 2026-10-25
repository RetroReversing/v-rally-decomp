#include "common.h"

s32 func_80098998(s8 *arg0, s32 arg1, s32 arg2)
{
  s8 *p;
  s8 *q;
  s32 n;
  s8 c;
  p = arg0 + arg2;
  if ((*p) < 0x35)
  {
    *p = 0;
    return arg1;
  }
  if (c)
  {
    q = p;
    n = arg2 - 1;
    *q = 0;
  }
  else
  {
    q = p;
    n = arg2 - 1;
    *q = 0;
  }
  if (n < 0)
  {
    goto end;
  }
  do
  {
    p--;
    c = *p;
    if (c != 0x39)
    {
      *p = c + 1;
      return arg1;
    }
    *p = 0x30;
 n--; } while (n >= 0); end: *p = 0x31; q[0] = 0x30; q[1] = 0;
  return arg1 + 1;
}
