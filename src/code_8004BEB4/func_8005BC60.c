#include "common.h"

s32 func_80035438();
extern s32 D_800A1468;
void func_8005BC60(void)
{
  s32 temp_a0;
  s32 temp_s1;
  s32 var_s0;
  unsigned long new_var;
  var_s0 = 0;
  do
  {
    new_var = (var_s0 & 0xFF) * 4;
    temp_s1 = new_var;
    temp_a0 = *((s32 *) (((char *) (temp_s1 + D_800A1468)) + 0x184));
    if (temp_a0 != 0)
    {
      func_80035438(temp_a0);
    }
    var_s0 += 1;
    *((s32 *) (((char *) (temp_s1 + D_800A1468)) + 0x184)) = 0;
  }
  while (((u32) (var_s0 & 0xFF)) < 4U);
}
