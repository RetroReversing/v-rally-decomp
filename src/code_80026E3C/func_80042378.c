#include "snapshot29_0433f7af8f6d.h"

extern char D_800AE850[];
extern char D_800C02AE[];
s32 func_8004240C();
s32 func_80042378(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  char pad[8];
  s32 *var_s1;
  s32 *var_v1;
  s32 temp_s0;
  s32 temp_v0;
  s32 flag;
  s32 temp_a0;
  s32 temp_a3;
  s32 cont;
  u8 temp_v0_2;
  var_s1 = NULL;
  temp_v0_2 = ((u8 *) *(void **) (D_800C02AE + 0x32F2))[0xF];
  var_v1 = *(s32 **) (*(void **) (D_800AE850 + 0x73F0));
  flag = temp_v0_2 != 0;
  if (temp_v0_2)
  {
    temp_a3 = 1;
    arg1 &= 0xFF;
    do
    {
      if (temp_a3 == arg1)
      {
        var_s1 = var_v1;
      }
      var_v1 = *(s32 **) ((char *) var_v1 + 4);
      cont = (u32) var_s1 < 1;
      cont = flag & (u8)cont;
    }
    while (cont);
    arg3 = temp_a3;
  }
  temp_s0 = (arg0 - 1) * 2;
  temp_v0 = func_8004240C(temp_s0 | 1, arg1, flag, arg3);
  temp_a0 = temp_s0 + 2;
  temp_s0 = temp_v0;
  temp_v0 = func_8004240C(temp_a0);
  *(s32 **) ((char *) temp_s0 + 0x24) = var_s1;
  *(s32 **) ((char *) temp_v0 + 0x24) = var_s1;
  return 1;
}
