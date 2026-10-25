#include "common.h"

extern char D_800A5008[];
extern char D_800AE850[];
s32 func_800520D4();

void func_80052194(s32 arg0)
{
  char pad[8];
  s32 *var_s4;
  char (*new_var)[];
  s32 var_a0;
  s32 var_a1;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  s32 var_s3;
  u8 *var_v0;
  var_s3 = arg0;
  var_s2 = 0;
  var_s0 = 0;
  if (var_s3 > 0)
  {
    new_var = &D_800A5008;
    var_s4 = (s32 *)new_var;
    var_s1 = 0;
    do
    {
      var_v0 = (u8 *)(var_s1 + *(u32 *)(D_800AE850 + 0x237C));
      if (*var_v0 == (s32)new_var)
      {
        var_a1 = var_s2 & 0xFFFF;
        var_s2 += 1;
        var_a0 = var_s0 & 0xFFFF;
        func_800520D4(var_a0, var_a1);
      }
      var_s0 += 1;
      var_s1 += 0x14;
    }
    while (var_s0 < var_s3);
  }
}
