#include "common.h"

s32 func_80098180();
extern s32 D_8009FEE0;

u8 func_800401FC(s32 arg0)
{
  s32 *var_s0;
  s32 var_s1;

  var_s0 = &D_8009FEE0;
  var_s1 = arg0;
  if (*var_s0 != 0)
  {
    do {
      if (func_80098180(var_s1, var_s0) == 0)
      {
        return *((u8 *) var_s0 + 4);
      }
      var_s0 += 2;

    } while (*var_s0 != 0);
  }
  return 1;
}
