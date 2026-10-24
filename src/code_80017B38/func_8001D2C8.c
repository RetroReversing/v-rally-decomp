#include "common.h"

void *func_8003FFB4();
s32 func_8008E118();
s32 func_80098370();
extern char D_800A47BC[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_8004CEB4;
static inline char *inline_fn(char *arg0, int arg1)
{
  return arg0 + arg1;
}

void func_8001D2C8(s32 *arg0)
{
  s32 *var_a1;
  s32 *var_s1;
  s32 *var_v1;
  s32 temp_v0;
  s32 var_a0;
  s32 var_a2;
  s32 var_s0;
  void *temp_v0_2;
  void *var_v0;
  var_s1 = arg0;
  var_s0 = inline_fn(var_s1, 0x4C);
  var_a0 = var_s0;
  temp_v0 = func_8008E118(var_a0);
  var_a0 = var_s0;
  var_a1 = &D_800A47BC;
  var_a1 = &D_800A47BC;
  var_a2 = temp_v0;
  func_80098370(var_a0, &D_800A47BC, var_a2);
  var_v0 = inline_fn(D_800C02AE, 0x5A82);
  var_v0 = *((void **) inline_fn(D_800C02AE, 0x5A82));
  var_a0 = *((s32 *) inline_fn((char *) var_v0, 0x10));
  var_a1 = var_s1;
  temp_v0_2 = func_8003FFB4(var_a0, var_a1);
  var_a0 = *((s32 *) (((char *) temp_v0_2) + 0x80));
  var_a1 = &func_8004CEB4;
  var_v1 = var_a1;
  var_v1 = &func_8004CEB4;
  *((void **) (D_800AE850 + 0x8A28)) = temp_v0_2;
  *((s32 **) (((char *) temp_v0_2) + 0x88)) = var_a1;
  var_a0 |= 0xC0;
  *((s32 *) (((char *) temp_v0_2) + 0x80)) = var_a0;
}
