#include "common.h"

s16 func_8002E810();
s16 func_8002E888(s32 arg0)
{
  int new_var;
  int new_var2;
  s16 temp_s0;
  s32 temp_s0_2;
  temp_s0_2 = ((s32) (arg0 << 0x10)) >> 0x14;
  new_var = func_8002E810(temp_s0_2);
  temp_s0 = new_var;
  new_var2 = func_8002E810(temp_s0_2 + 1) - temp_s0;
  return (s16) (temp_s0 + (((arg0 & 0xF) * new_var2) / 15));
}
