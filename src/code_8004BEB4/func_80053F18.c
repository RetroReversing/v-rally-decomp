#include "common.h"

extern char D_800C02AE[];
static inline s32 inline_fn(void *arg0)
{
  return (s32) arg0;
}

s32 func_80053F18(s32 arg0)
{
  s32 var_a0;
  char *new_var2;
  s32 var_v0;
  int new_var3;
  long new_var;
  u8 var_v1;
  void *var_a1;
  var_a1 = D_800C02AE + 0x32F2;
  new_var3 = 0x32;
  var_a1 = *((void **) (D_800C02AE + 0x32F2));
  var_a0 = arg0 & 0xFFFF;
  var_a0 = inline_fn(var_a1 + var_a0);
  new_var2 = ((char *) var_a0) + new_var3;
  var_v1 = *((u8 *) new_var2);
  var_v0 = var_v1 * 4;
  new_var = var_v1 * 5;
  var_v0 = new_var;
  var_v0 = var_v1 * 0x28;
  var_v0 += 0x44;
  ;
  return inline_fn(var_a1 + var_v0);
}
