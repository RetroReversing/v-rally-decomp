#include "snapshot29_0433f7af8f6d.h"

extern s32 D_800AE850;
extern char *D_800D0648;
extern u16 D_800D0628;
void func_80052C18(void)
{
  volatile char pad[8];
  u32 i;
  u16 bit;
  char **pp;
  char *p;
  s16 *dst;
  u16 *count;
  pp = &D_800D0648;
  p = *pp;
  i = 0;
  if (D_800D0628 != 0)
  {
    bit = 1;
 do { count = (u16 *) (((char *) pp) - 0x20); } while (0);
    dst = (s16 *) (((char *) (&D_800AE850)) + 0x7DB0);
    do
    {
      dst[i + 8] = 0;
      if ((*((u16 *) (p + 0x10))) & 2)
      {
        dst[i + 8] = bit;
      }
      p += 0x2C4;
      i++;
    }
    while (i < (*count));
  }
}
