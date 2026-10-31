#include "snapshot31_manual_verified.h"

extern s8 D_800AE850[];
extern s8 D_800C02AE[];
void func_80086A34(s32 arg0)
{
  char pad[8];
  s32 i;
  s32 count;
  s32 saved;
  s32 unused = 0;
  s32 orig;
  char *rec;
  (void) pad;
  arg0 &= 0xFFFF;
  unused = arg0;
  saved = unused;
  if (arg0 == 0)
  {
    arg0 = 1;
  }

  count=*(s32*)0x800C782C;
  rec=*(char**)0x800B68F0;
  i=0;

  if (count > 0)
  {
    orig = unused;
    saved = count;
    rec += 0x18;
    do
    {
      if ((*((u16 *) (rec + 0x86))) == 0)
      {
        *((s32 *) (rec - 0xC)) = orig;
        *((s32 *) rec) = arg0;
      }
      i++;
      rec += 0x134;
    }
    while (i < saved);
  }
}
