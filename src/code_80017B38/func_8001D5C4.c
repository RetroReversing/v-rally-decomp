#include "common.h"

s32 func_800401FC();
extern char D_800AE850[];
void func_8001D5C4(s32 arg0)
{
  s32 temp_v0;
  u8 var_v1;
  s16 *var_a0;

  temp_v0 = func_800401FC(arg0 + 0x4C);
  var_a0 = *((s16 **) (D_800AE850 + 0x8A28));
  if (var_a0 != NULL)
  {
    var_v1 = temp_v0;
    if (var_v1 != 0)
    {
      var_a0[0x6E / 2] = var_v1;
    }
  }
}
