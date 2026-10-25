#include "common.h"

s32 func_80022184();
s32 func_80022F98();
extern s32 D_8009D538;
extern char D_800AE850[];
extern char D_800C02AE[];

void func_80022744(void)
{
  s32 *var_s0;
  s32 var_s1;
  s32 temp_a0;

  if (!(D_8009D538 & 2))
  {
    if (func_80022184(D_800AE850 + 0x7320) != 0)
    {
      var_s1 = 0;
      var_s0 = (s32 *) (D_800C02AE + 0x7162);
      do
      {
        temp_a0 = *var_s0;
        var_s0++;
        func_80022F98(temp_a0);
        var_s1++;
      }
      while (var_s1 == 0);
    }
  }
}
