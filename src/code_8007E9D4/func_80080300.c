#include "common.h"

s32 func_8007EAA0();
s32 func_80080148();
s32 func_80097E30();
s32 func_80080300(s32 arg0, s32 arg1, unsigned short arg2)
{
  s32 temp_v0;
  temp_v0 = func_8007EAA0(6);
  func_80097E30(temp_v0, 0, arg1);
  func_80080148(temp_v0, arg0, arg2 & 0xFFFF);
  return temp_v0;
}
