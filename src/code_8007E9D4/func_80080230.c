#include "common.h"

s32 func_8007EAA0();
s32 func_80080148();
s32 func_80097E30();
s32 func_80080230(s32 arg0, s32 arg1, s32 arg2)
{
  unsigned short new_var;
  int new_var2;
  s32 temp_v0;
  new_var2 = 0xFFFF;
  new_var = arg2 & new_var2;
  temp_v0 = func_8007EAA0(1);
  func_80097E30(temp_v0, 0, arg1);
  func_80080148(temp_v0, arg0, new_var);
  return temp_v0;
}
