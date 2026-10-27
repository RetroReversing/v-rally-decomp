#include "common.h"

extern s32 D_800C02AE[];
extern s32 D_800AE850[];
s32 func_80086D34(s32 *arg0)
{
  s32 i;
  s32 flag;
  s32 count;
  int new_var2;

  s32 *p;
  s32 **new_var;
  flag = 1;
  count = *((s32 *) (((u8 *) D_800C02AE) + 0x757E));
  p = *(new_var = &(*((s32 **) (((u8 *) D_800AE850) + 0x80A0))));
  new_var2 = 0;
  i = 0;
  if (count > new_var2)
  {
    s32 key = arg0[1];
    do
    {
      i++;
      flag &= -(((*((s32 *) (((u8 *) p) + 0x40))) ^ key) != 0);
      p = (s32 *) (((u8 *) p) + 0x134);
    }
    while ((i < count) && (flag != 0));
  }
  return flag;
}
