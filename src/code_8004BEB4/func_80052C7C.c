#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800AE850;
extern u16 D_800D0628;
extern u8 *D_800D0648;
s32 func_80052C7C(void)
{
  u16 *new_var;
  s32 pad;
  u32 i;
  s32 count;
  u8 *pp;
  u8 *base;
  u8 *p;
  u8 *flag;
  u16 enabled;
  (void) (&pad);
  i = 0;
  enabled = D_800D0628;
  pp = (u8 *) (&D_800D0648);
  base = *((u8 **) pp);
  count = 0;
  if (enabled)
  {
    new_var = (u16 *) (pp - 0x20);
    flag = (&D_800AE850) + 0x7DB0;
    p = base + 0x10;
    do
    {
      u16 v = (*((u16 *) p)) & 0xFFFD;
      *((u16 *) p) = v;
      if (*((u16 *) (flag + 0x10)))
      {
        *((u16 *) p) = v | 2;
        count++;
      }
      p += 0x2C4;
      i++;
      flag += 2;
    }
    while (i < (*new_var));
  }
  return count;
}
