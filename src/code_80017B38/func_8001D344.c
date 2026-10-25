#include "common.h"

/* identical to func_8001D258 (matched), with its names changed by decompdecomp */
void *func_8003FFB4();
s32 func_8008E118();
s32 func_80098370();
extern char D_800A47BC[];
extern char D_800AE850[];
extern char D_800C02AA[];
void func_8001D344(s32 *arg0)
{
  s32 *var_a1;
  s32 temp_v0;
  s32 var_a0;
  s32 var_a2;
  s32 var_s0;
  s32 var_v1;
  void *temp_v0_2;
  void *var_v0;
  int new_var;
  temp_v0_2 = arg0;
  var_s0 = temp_v0_2 + 0x4C;
  var_a0 = var_s0;
  temp_v0 = func_8008E118(var_a0);
  var_a1 = &D_800A47BC;
  var_a0 = var_s0;
  var_a1 = &D_800A47BC;
  var_a2 = temp_v0;
  func_80098370(var_a0, &D_800A47BC, var_a2);
  var_v0 = D_800C02AA + 0x5A76;
  var_v0 = *((void **) (D_800C02AA + 0x5A76));
  var_a0 = *((s32 *) (var_v0 + 0x10));
  var_a1 = temp_v0_2;
  temp_v0_2 = func_8003FFB4(var_a0, var_a1);
  var_v1 = *((s32 *) (((char *) temp_v0_2) + 0x80));
  *((void **) (D_800AE850 + 0x8A28)) = temp_v0_2;
  var_v1 |= 0x40;
  new_var = 0x80;
  *((s32 *) (((char *) temp_v0_2) + new_var)) = var_v1;
}
