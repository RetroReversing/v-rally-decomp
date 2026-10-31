#include "snapshot31_verified.h"

s8 *func_8002A960(s8 *p, s8 *end)
{
  s32 k = 13;
 do { if ((*(p++)) != k) { s32 cr = 13; scan: if (p >= end) { goto tail; } if ((*(p++)) != cr) { goto scan; } } tail: if (p == end) { goto done; } } while (0);
  do
  {
    p++;
    if ((*p) != k)
    {
      break;
    }
    p++;
  }
  while ((short) (p != end));
  done:
  return p;

}
