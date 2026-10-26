#include "common.h"

s32 __osMotorAccess();
s32 osMotorInit();
extern s32 D_800A1B70;
extern char D_800AE850[];
static inline int inline_fn(s32 arg0)
{
  return (arg0 * 0x68) + 0x18C;
}

void func_800863B0(s32 arg0, s32 arg1)
{
  s32 temp_s0;
  void *temp_s1;
  if (arg1 & 0xFF)
  {
    osMotorInit(D_800AE850 + 0x5A38, D_800A1B70 + inline_fn(arg0), arg0);
  }
  temp_s1 = D_800AE850 + 0x5A38;
  temp_s0 = inline_fn(arg0);
  osMotorInit(temp_s1, D_800A1B70 + temp_s0, arg0);
  __osMotorAccess(D_800A1B70 + temp_s0, 0);
  osMotorInit(temp_s1, D_800A1B70 + temp_s0, arg0);
  __osMotorAccess(D_800A1B70 + temp_s0, 0);
  osMotorInit(temp_s1, D_800A1B70 + temp_s0, arg0);
  __osMotorAccess(D_800A1B70 + temp_s0, 0);
}
