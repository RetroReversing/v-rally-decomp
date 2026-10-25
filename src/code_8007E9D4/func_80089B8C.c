#include "common.h"

void func_80089B8C(u8 *arg0)
{
  u8 *temp_s0;
  u8 *temp_v0;
  u8 var_a2;
  s32 temp_a1;
  temp_s0 = (*((u8 **) (arg0 + 0x10))) + ((*((s16 *) (arg0 + 2))) * 0x14);
  var_a2 = 0;
  if (temp_s0[0xC] != 0)
  {
    do
    {
      ;
      if (((*((void (**)(s32, s32, s32)) ((*((u8 **) (temp_s0 + 8))) + (var_a2 * 0xC)))) != NULL) && (((*((u8 **) (temp_s0 + 8))) + (var_a2 * 0xC))[0xA] != 0))
      {
        temp_a1 = var_a2 + temp_s0[0xD];
        (*((void (**)(s32, s32, s32)) ((*((u8 **) (temp_s0 + 8))) + (var_a2 * 0xC))))(temp_a1 == temp_s0[0xE], temp_a1, var_a2);
      }
      var_a2++;
    }
    while (var_a2 < temp_s0[0xC]);
  }
  if ((*((void (**)()) temp_s0)) != NULL)
  {
    (*((void (**)()) temp_s0))();
  }
}
