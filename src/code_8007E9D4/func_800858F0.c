#include "common.h"

s32 func_800857EC();
s32 func_800858A4();
extern char *D_800A1B70;
s32 func_800858F0(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_s0;
  s32 var_a0;
  s32 var_v1;
  s32 var_v0;
  temp_s0 = arg0 & 0xFF;
  if (func_800858A4(temp_s0, arg1 & 0xFF, 0) != 0)
  {
    var_a0 = *((s32 *) ((D_800A1B70 + (temp_s0 * 4)) + 0x38C));
    if ((*((s32 *) (var_a0 + 8))) != 2)
    {
      var_v1 = var_a0;
      var_a0 = 2;
      do
      {
        var_v0 = *((vs32 *) (var_v1 + 8));
      }
      while (var_v0 != var_a0);
    }
    if (func_800857EC(arg0 & 0xFF, arg1 & 0xFF, arg2 & 0xFF) != 0)
    {
      return 1;
    }
  }
  return 0;
}
