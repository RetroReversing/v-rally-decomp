#include "common.h"

void *func_8008A054();
void func_8008A1CC(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
  char *var_a0;
  s32 temp_s0;
  u32 var_a1;
  void *temp_a2;
  volatile int pad;
  void *temp_v0;
  void *var_v1;
  temp_s0 = arg1 & 0xFFFF;
  temp_v0 = func_8008A054(arg0, temp_s0);
  temp_a2 = (*((s32 *) (((char *) temp_v0) + 8))) + ((temp_s0 - (*((u8 *) (((char *) temp_v0) + 0xD)))) * 0xC);
  var_a0 = *((s32 **) (((char *) temp_a2) + 4));
  var_a1 = 0;
  if ((*((u8 *) (((char *) temp_a2) + 8))) != 0)
  {
    var_v1 = var_a0 + 8;
    loop_2:
    var_a1 += 1;

    if (((*((s32 *) var_a0)) == arg2) && ((*((s8 *) (((char *) var_v1) + (-4)))) == 0))
    {
      *((s32 *) (((char *) var_v1) + 0)) = arg3;
      return;
    }
    var_v1 += 0xC;
    var_a0 += 0xC;
    if (var_a1 >= ((u8) (*((u8 *) (((char *) temp_a2) + 8)))))
    {
    }
    else
    {
      goto loop_2;
    }
  }
}
