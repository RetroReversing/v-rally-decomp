#include "checkpoint_common.h"

void func_8002D830();
s32 *func_8002D8A0(s16 *arg0, s32 *arg1, s32 *arg2)
{
  s32 sp10[3];
  s32 temp_a1;
  s32 temp_a2;
  s32 var_v0;
  func_8002D830();
  temp_a1 = arg0[0];
  temp_a1 *= arg1[0];
  temp_a1 += arg0[1] * arg1[1];
  temp_a1 += arg0[2] * arg1[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a2 = var_v0 >> 12;
  sp10[0] = temp_a2;
  temp_a1 = arg0[3];
  temp_a1 *= arg1[0];
  temp_a1 += arg0[4] * arg1[1];
  temp_a1 += arg0[5] * arg1[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a1 = var_v0 >> 12;
  sp10[1] = temp_a1;
  temp_a1 = arg0[6];
  temp_a1 *= arg1[0];
  temp_a1 += arg0[7] * arg1[1];
  temp_a1 += arg0[8] * arg1[2];
  if (temp_a1 >= 0)
  {
    var_v0 = temp_a1;
  }
  else
  {
    var_v0 = temp_a1 + 0xFFF;
  }
  temp_a1 = var_v0 >> 12;
  sp10[2] = temp_a1;
  arg2[0] = temp_a2;
  arg2[1] = sp10[1];
  arg2[2] = sp10[2];
  return arg2;
}
