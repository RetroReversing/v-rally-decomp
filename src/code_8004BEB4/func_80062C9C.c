#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800C02AE[];
extern s32 func_800592F4(s32, s32);
s32 func_80062C9C(s32 arg0)
{
  u8 *p = *((u8 **) (D_800C02AE + 0x32F2));
  u8 **new_var;
  u32 b = p[0x30];
  s32 v;
  if (((u8) b) != 0)
  {
    if (((u8) b) < 2)
    {
      goto skip;
    }
    v = b;
    v = v;
    v = v - 1;
  }
  else
  {
    v = 9;
  }
 do { p[0x30] = v; } while (0);
  new_var = (u8 **) (D_800C02AE + 0x32F2);
  skip:
  func_800592F4(arg0, (*new_var)[0x30]);

  return 0;
}
