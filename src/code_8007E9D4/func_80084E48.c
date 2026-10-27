#include "common.h"

extern s32 D_800A1B70;
void func_80084E48(s32 arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4)
{
  unsigned short off;
  s32 h = ((u16 *) (&arg4))[1];
  if (arg1 == 0x20000)
  {
    s32 base = D_800A1B70;
    if (1)
    {
      off = (arg0 & 0xFF) * 0x14;
      *((s8 *) ((base + off) + 0x5F)) = arg2;
      *((s8 *) ((D_800A1B70 + off) + 0x5C)) = h;
    }
    *((s8 *) ((D_800A1B70 + off) + 0x5D)) = arg3;
  }
  else
    if (arg1 == 0x10000)
  {
    s32 base = D_800A1B70;
    off = (arg0 & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x64)) = arg2;
    *((s8 *) ((D_800A1B70 + off) + 0x61)) = h;
    *((s8 *) ((D_800A1B70 + off) + 0x62)) = arg2;
  }
}
