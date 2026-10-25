#include "common.h"

s32 func_8006F5E8();
s32 func_8006F628();
s32 func_8006F890();
s32 func_80084AFC();
s32 func_80084B50();
s32 func_8008F5F0();
extern s32 D_8009F640;
extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_8006F69C(void)
{
  s32 temp_v0;
  s32 new_var;
  s32 var_s0;
  s32 var_v0;
  void *temp_s1;
  var_v0 = D_8009F640 & 0x8000;
  if (var_v0 == 0)
  {
    temp_s1 = D_800C02AE + 0x6E22;
    var_s0 = 0;
    func_80084AFC();
    do
    {
      temp_v0 = func_8008F5F0(D_800AE850 + 0x5A38, var_s0 & 0xFF, temp_s1 + ((var_s0 & 0xFFFF) * 8));
      var_s0 += 1;
    }
    while (((u32) (var_s0 & 0xFFFF)) < 0x40U);
    func_80084B50();
    var_v0 = temp_v0;
    if (func_8006F890(temp_s1 + 4, 0x1FC) != (*((s32 *) (D_800C02AE + 0x6E22))))
    {
      var_v0 = temp_v0;
      new_var = func_8006F5E8();
      if (new_var != 0)
      {
        func_8006F628();
        ;
      }
    }
    return temp_v0;
  }
}
