#include "common.h"

s32 func_8004ECA8(u16 *arg0, u16 *arg1)
{
  s32 var_a2;
  s32 var_a3;

  var_a2 = arg0[1];
  var_a3 = 0;
  if (arg0[3] == 0 && arg0[0] != 2)
  {
    if (var_a2 == 1)
    {
      var_a2 = 2;
    }
    else
    {
      var_a2 -= 1;
    }
    if (arg1[3] != 0)
    {
      var_a2 -= arg1[1];
    }
  }
  if (var_a2 == 0 || arg0[0] == 4)
  {
    var_a3 = 1;
  }
  return var_a3;
}
