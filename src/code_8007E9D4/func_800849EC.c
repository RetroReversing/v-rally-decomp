#include "common.h"

extern int D_800B7334;
extern unsigned short D_800C3384;
s32 func_80081E8C();
s32 func_80082290();
s32 func_80084740();
extern char D_800AE850[];
extern char D_800C02AE[];
void func_800849EC(s32 arg0)
{
  s32 *var_v0;
  s32 var_a1;
  s32 var_v1;
  void *var_a0;
  var_v0 = D_800AE850 + 0x8AE0;
  var_v1 = *var_v0;
  var_a1 = arg0 * 8;
  var_a0 = var_v0;
  var_a0 = var_a0 - 8;
  var_v1 += var_a1;
  D_800B7334 = var_v1;
  var_a1 = 4;
  func_80081E8C(var_a0, 4);
  func_80084740();
  var_a0 = D_800C02AE + 0x30D6;
  var_a0 = (void *) D_800C3384;
  func_80082290(var_a0);
}
