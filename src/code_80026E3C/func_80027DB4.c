#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern char D_800AE850[];
extern char D_800C02AE[];
s8 func_80027DB4(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_a0;
  s32 var_v1;
  s32 step;
  var_v1 = *((s32 *) ((D_800C02AE + 0x8062) + ((arg2 & 255) * 4)));
  if (var_v1 >= 151)
  {
    var_v1 = 25;
    step = 20;
  }
  else if (var_v1 >= 101)
  {
    var_v1 = 30;
    step = 20;
  }
  else
  {
    var_v1 = 35;
    step = 20;
  }
  if (arg1 == 0)
  {
    var_v1 = 0;
  }
  else if (arg1 > 0)
  {
    temp_a0 = *((s32 *) ((D_800AE850 + 0x58F8) + ((arg2 & 255) * 4)));
    if (temp_a0 >= var_v1)
    {
      var_v1 = temp_a0 + step;
    }
    if (var_v1 >= 128)
    {
      var_v1 = 127;
    }
  }
  else if (arg1 < 0)
  {
    temp_a0 = *((s32 *) ((D_800AE850 + 0x58F8) + ((arg2 & 255) * 4)));
    var_v1 = -var_v1;
    if (var_v1 >= temp_a0)
    {
      var_v1 = temp_a0 - step;
    }
    if (var_v1 < (-128))
    {
      var_v1 = -128;
    }
  }
  else
  {
    var_v1 = 0;
  }
  *((s32 *) ((D_800AE850 + 0x58F8) + ((arg2 & 255) * 4))) = var_v1;
  return var_v1;
}
