#include "common.h"

extern u8 D_800C02AE[];
s8 func_80068658(s8 arg0)
{
  s8 a3;
  u8 found;
  u8 *base;
  base = (*((u8 **) (D_800C02AE + 0x32F2))) + 0x44;
  a3 = arg0;
  found = 0;
  if (arg0 < 3)
  {
    arg0 += 1;
    while (1)
    {
      if (((u32) (base[arg0 * 0x28] - 0x41)) < 0x1A)
      {
        found = 1;
        break;
      }
      if (arg0 >= 3)
      {
        break;
      }
      arg0++;
    }

    if (found)
    {
      a3 = arg0;
    }
  }
  return a3;
}
