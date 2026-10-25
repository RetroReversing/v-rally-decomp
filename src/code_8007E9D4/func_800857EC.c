#include "common.h"

extern s32 D_800A1B70;
s32 func_800857EC(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_v1;
  s32 var_v0;
  void *temp_a1;
  void *temp_a3;
  var_v0 = 0;
  if ((arg1 & 0xFF) == 2)
  {
    temp_a1 = ((arg0 & 0xFF) * 4) + D_800A1B70;
    temp_a3 = *((void **) (((char *) temp_a1) + 0x38C));
    temp_v1 = *((s32 *) (((char *) temp_a3) + 4));
    if (temp_v1 != 1)
    {
      return 0;
    }
    *((vs32 *) (((char *) temp_a3) + 8)) = temp_v1;
    arg2 = arg2 & 0xFF;
    if (arg2 != 0)
    {
      *((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x38C)))) + 0xC)) = (s32) (0xFF / arg2);
    }
    else
    {
      *((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x38C)))) + 0xC)) = 0xFF;
    }
    var_v0 = 1;
    *((s32 *) (((char *) (*((void **) (((char *) (((arg0 & 0xFF) * 4) + D_800A1B70)) + 0x38C)))) + 0x10)) = 1;
    return var_v0;
  }
  return var_v0;
}
