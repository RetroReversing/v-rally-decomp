#include "common.h"

extern s8 *D_800A1B70;

void func_800862A0(s32 arg0)
{
  s32 off;
  s8 *base;

  base = D_800A1B70;
  off = arg0 * 0x14;
  *(base + off + 0x5C) = 0x3D;
  *(D_800A1B70 + off + 0x5E) = -7;
  *(D_800A1B70 + off + 0x5F) = 0;
  *(D_800A1B70 + off + 0x60) = 7;
  *(D_800A1B70 + off + 0x5D) = -0x3D;
  *(D_800A1B70 + off + 0x61) = 0x3F;
  *(D_800A1B70 + off + 0x63) = -7;
  *(D_800A1B70 + off + 0x64) = 0;
  *(D_800A1B70 + off + 0x65) = 7;
  *(D_800A1B70 + off + 0x62) = -0x3F;
}
