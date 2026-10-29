#include "snapshot29_0433f7af8f6d.h"

u64 osGetTime(void);
s32 func_80098090(void);
s32 func_800980C4(s32);
extern u8 D_800C02AE[];
void func_80036260(s16 *var_s4)
{
  s32 temp_ret_2;
  s32 temp_ret_3;
  s32 temp_ret_4;
  s32 temp_s3;
  s32 temp_v1;
  s32 var_s2 = 0;
  s32 var_s1 = 0;
  s32 var_s3;
  s32 temp_a1;
  s32 last;
  s8 *var_s0;
  s8 var_v0;
  var_s3 = *((s32 *) ((*((void **) (D_800C02AE + 0x7E6E))) + 8));
  func_800980C4((s32) osGetTime());
  if (!(var_s3--))
  {
    return;
  }
  ;
  do
  {
    ;
    switch (func_80098090() % 3)
    {
      case 0:
        var_s2 = 0x50;
        var_s1 = 0x8c;
        break;

      case 1:
        var_s2 = 0x28;
        var_s1 = 0x64;
        break;

      case 2:
        var_s2 = 0x80;
        var_s1 = 0xb4;
        break;

      case 3:
        var_s2 = 0x64;
        var_s1 = 0x82;
        break;

      default:
        break;

    }

    var_v0 = var_s2 - 5;
    (((s8 *) var_s4) + 12)[4] = var_v0;
    (((s8 *) var_s4) + 12)[5] = var_v0;
    (((s8 *) var_s4) + 12)[6] = var_s2 + 5;
    (((s8 *) var_s4) + 12)[1] = var_s1 - 5;
    (((s8 *) var_s4) + 12)[2] = var_s1 - 5;
    (((s8 *) var_s4) + 12)[3] = var_s1 + 10;
    temp_ret_2 = func_80098090();
    *var_s4 = temp_ret_2 % 8191;
    temp_ret_3 = func_80098090();
    *((s16 *) ((((s8 *) var_s4) + 12) - 10)) = temp_ret_3 % 2047;
    temp_ret_4 = func_80098090();
    *((s16 *) ((((s8 *) var_s4) + 12) - 8)) = temp_ret_4 % 8191;
    last = func_80098090();
    temp_a1 = var_s3--;
    (((s8 *) var_s4) + 12)[0] = (last % 50) + 20;
    var_s0 += 20;
    var_s4 += 10;
  }
  while (temp_a1);
}
