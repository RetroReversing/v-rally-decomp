#include "common.h"

s32 func_800592F4();
s32 func_8006FA8C();
extern char D_800C02AE[];
s32 func_80060054(void)
{
  s32 var_a2;
  s32 var_s0;
  s32 var_v0;
  s32 var_v1;
  long pad;
  u8 var_a0;
  short new_var;
  void *var_a1;
  var_s0 = 0;
  var_a2 = 1;
  new_var = 1;
  loop_1:
  var_a1 = D_800C02AE + 0x32F2;

  var_a1 = *((void **) (D_800C02AE + 0x32F2));
  var_a0 = *((u8 *) (((char *) var_a1) + 0x2F));
  var_v1 = var_s0 & 0xFF;
  var_v0 = (var_v0 = (s32) var_a0) >> var_v1;
  var_v0 &= 1;
  var_s0 += 1;
  if (var_v0 == 0)
  {
    do
    {
      var_v0 = new_var << var_v1;
    }
    while (0);
    var_v0 |= var_a0;
    *((u8 *) (((char *) var_a1) + 0x2F)) = (u8) var_v0;
  }
  else
  {
    var_v0 = var_s0 & 0xFF;
    var_v0 = ((u32) var_v0) < 4U;
    if (var_v0 != 0)
    {
      goto loop_1;
    }
  }
  func_8006FA8C(var_a0, var_a1, new_var);
  var_a0 = 0x1C;
  var_a1 = (void *) (var_s0 & 0xFF);
  func_800592F4(0x1C, var_a1);
  var_v0 = 0;
  return 0;
}
