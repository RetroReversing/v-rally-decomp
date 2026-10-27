#include "checkpoint_common.h"

s32 func_8002D830();
s32 *func_8002E288(s16 *arg0, s16 *arg1, s32 *arg2)
{
  s32 temp_a1;
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
  temp_a1 = var_v0 >> 12;
  arg2[0] = temp_a1;
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
  arg2[1] = temp_a1;
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
  arg2[2] = temp_a1;
  return arg2;
}
