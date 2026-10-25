#include "common.h"

extern s32 D_800A1B70;
s32 func_800858A4(u8 arg0, u8 arg1, u8 arg2)
{
  s32 *temp_a0;
  s32 temp_a1;

  if (arg1 != 2)
  {
    return 0;
  }
  temp_a1 = (arg0 * 4) + D_800A1B70;
  temp_a0 = *(s32 **)(temp_a1 + 0x38C);
  if (temp_a0[1] != 1)
  {
    return 0;
  }
  temp_a0[2] = 0;
  *(u8 *)((char *)*(s32 **)(temp_a1 + 0x38C) + 0x14) = arg2;
  return 1;
}
