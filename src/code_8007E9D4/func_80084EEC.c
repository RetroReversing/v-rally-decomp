#include "common.h"

extern s32 D_800A1B70;
void func_80084EEC(s32 arg0, s32 arg1, s8 arg2, s8 arg3)
{
  unsigned short off;
  if (arg1 == 0x20000)
  {
    s32 base = D_800A1B70;
    off = (arg0 & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x5E)) = arg2;
    *((s8 *) ((D_800A1B70 + off) + 0x60)) = arg3;
  }
  else if (arg1 == 0x10000)
  {
    s32 base = D_800A1B70;
    off = (arg0 & 0xFF) * 0x14;
    *((s8 *) ((base + off) + 0x63)) = arg2;
    *((s8 *) ((D_800A1B70 + off) + 0x65)) = arg3;
  }
}
