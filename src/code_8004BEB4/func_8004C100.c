#include "snapshot29_0433f7af8f6d.h"

void func_8004C2B8(s32, s32, s32, s32, s32, s32);
void func_8004C100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4)
{
  s32 var_s5 = arg0;
  s32 var_s4 = arg3;
  u16 var_s1 = var_s4 - 0x10;
  s32 var_s0 = arg2 & 0xFFFF;
  u16 var_s2 = arg4;
  u16 new_var;
  s32 var_s3 = 0xCC;
  var_s1 &= 0xFFFF;
  func_8004C2B8(var_s5, arg1 & 0xFFFF, var_s0, var_s1, var_s0, var_s3);
  var_s2 &= 0xFFFF;
  func_8004C2B8(var_s5, var_s1, var_s0, var_s1, var_s2, var_s3);
  new_var = var_s2;
  var_s2 = var_s4;
  func_8004C2B8(var_s5, var_s1, new_var, var_s2 & 0xFFFF, new_var, var_s3);
}
