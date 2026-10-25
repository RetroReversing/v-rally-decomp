#include "common.h"

void *func_8002B180();
u32 func_8002B2DC(s8 *arg0, u32 arg1, s8 *arg2)
{
  s8 *var_a0;
  var_a0 = func_8002B180(arg0);
  if (((u32) var_a0) >= arg1)
  {
    *arg2 = 0;
 do { var_a0 = (s8 *) arg1; } while (0);
  }
  else
    if ((*var_a0) == 0x5B)
  {
    *arg2 = 0;
  }
  else
  {
    *arg2 = 1;
  }
  return (u32) var_a0;
}
