#include "common.h"

s32 __osMotorAccess();
extern s32 D_800A1B70;
void func_80086370(s32 arg0)
{
  int new_var;
  new_var = (arg0 * 0x68) + 0x18C;
  __osMotorAccess(D_800A1B70 + new_var, 1);
}
