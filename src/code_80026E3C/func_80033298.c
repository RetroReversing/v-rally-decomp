#include "snapshot29_0433f7af8f6d.h"

void func_80033298(u8 *arg0)
{
  u8 *a1 = *((u8 **) (arg0 + 0x78));
  u8 *a2;
  s32 v0;
  s32 cond;
  s8 *new_var;
  s32 lo;
  s32 hi;
  u8 *tail;
  *((s8 *) (a1 + 0x15)) = 0x32 - (((s16) (*((u16 *) (a1 + 4)))) / 40);
  lo = a1[0xE];
  hi = a1[0xF];
  cond = lo < hi;
  a2 = *((u8 **) (arg0 + 0x78));
  *((s8 *) (a2 + 0x16)) = 0x32 + (((s16) (*((u16 *) (a2 + 6)))) / 40);
  if (cond)
  {
    if (hi || arg0)
    {
      *((s8 *) ((*((u8 **) (arg0 + 0x78))) + 0x14)) = (*((u8 **) (arg0 + 0x78)))[0x16];
      tail = *((u8 **) (arg0 + 0x78));
      v0 = tail[0x15];
    }
    else
    {
      *((s8 *) ((*((u8 **) (arg0 + 0x78))) + 0x14)) = (*((u8 **) (arg0 + 0x78)))[0x16];
      tail = *((u8 **) (arg0 + 0x78));
      v0 = tail[0x15];
    }
  }
  else
  {
    new_var = (s8 *) ((*((u8 **) (arg0 + 0x78))) + 0x14);
    *new_var = (*((u8 **) (arg0 + 0x78)))[0x15];
    tail = *((u8 **) (arg0 + 0x78));
    v0 = tail[0x16];
  }
  tail[0x17] = v0;
}
