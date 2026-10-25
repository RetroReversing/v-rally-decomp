#include "common.h"

extern u8 D_800C02AE[];
s8 func_800686D8(s8 arg0)
{
  u8 found;
  s8 i;
  u8 *tbl;
  tbl = (*((u8 **) (D_800C02AE + 0x32F2))) + 0x44;
  found = 0;
  if (arg0 != 0)
  {
    i = arg0 - 1;
    while (1)
    {
      if (((u8) (tbl[i * 40] - 0x41)) <= (0x1A - 1))
      {
        found = 1;
        break;
      }
      if (i == 0)
      {
        break;
      }
      i--;
    }

    if (found)
    {
      arg0 = i;
    }
  }
  return arg0;
}
