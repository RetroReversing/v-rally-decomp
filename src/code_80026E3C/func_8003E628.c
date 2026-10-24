#include "common.h"

s32 func_8003C354();
extern char D_800C02AE[];
void func_8003E628(s32 arg0, s32 arg1)
{
  char *new_var;
  s32 temp_a2;
  s32 var_s0;
  u16 temp_v0;
  if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x1E))) != 7)
  {
    temp_v0 = *((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE));
    var_s0 = 1;
    if (temp_v0 != 0)
    {
      do
      {
        temp_a2 = var_s0 & 0xFFFF;
        new_var = (char *) ((*((void **) (D_800C02AE + 0x32F2))) + ((*((u8 *) (((char *) ((*((void **) (D_800C02AE + 0x32F2))) + temp_a2)) + 0x31))) * 0x28));
        if ((*((u8 *) (new_var + 0x48))) & 2)
        {
          func_8003C354(arg0, arg1, temp_a2);
        }
        var_s0 += 1;
      }
      while (temp_v0 >= ((u32) (var_s0 & 0xFFFF)));
    }
  }
}
