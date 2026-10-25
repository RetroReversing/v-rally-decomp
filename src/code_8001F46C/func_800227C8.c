#include "common.h"

s32 func_80022184();
s32 func_80022200();
s32 func_80080478();
s32 func_800804C4();
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_80022E64;

void func_800227C8(void)
{
  s32 *var_s0;
  s32 temp_a0;
  s32 var_s1;

  if (func_80022184(D_800AE850 + 0x7320) != 0)
  {
    var_s1 = 0;
    var_s0 = (s32 *) (D_800C02AE + 0x7162);
    do
    {
      var_s1 += 1;
      func_800804C4(*var_s0, &func_80022E64);
      temp_a0 = *var_s0;
      var_s0 += 1;
      func_80080478(temp_a0);
    }
    while (var_s1 == 0);
    func_80022200(D_800AE850 + 0x7320);
  }
}
