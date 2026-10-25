#include "common.h"

s32 func_80014598();
void func_80014D84(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
  u32 a;
  u32 b;

  a = (arg0 + arg2) >> 1;
  b = (arg1 + arg3) >> 1;
  func_80014598(a, arg1, a, arg3, arg4);
  func_80014598(arg0, b, arg2, b, arg4);
}
