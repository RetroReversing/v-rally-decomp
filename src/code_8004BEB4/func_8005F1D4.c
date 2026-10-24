#include "common.h"

extern unsigned short D_800C3556;
s32 func_800592F4();
extern char D_800C02AE[];
s32 func_8005F1D4(s32 arg0)
{
  u16 *var_a1;
  u16 var_v0;
  u16 var_v1;
  var_a1 = D_800C02AE + 0x32A8;
  var_v1 = *var_a1;
  var_v0 = var_v1 & 1;
  if (!(var_v0 == 0))
  {
    var_v0 = var_v1 & 0xFFFE;
  }
  else
  {
    var_v0 = var_v1 | 1;
  }
  *var_a1 = var_v0;
  var_a1 = D_800C02AE + 0x32A8;
  var_a1 = (u16 *) D_800C3556;
  var_a1 = (u16 *) (((s32) var_a1) & 1);
  func_800592F4(arg0, var_a1);
  var_v0 = 0;
  return 0;
}
