#include "common.h"

void func_80033CD4(void *arg0, s32 arg1, void *arg2)
{
  s32 var_v1;
  s32 temp_a1;
  u8 *new_var;
  u16 temp_t0;
  void *var_a3;
  void *temp_a0;
  var_a3 = arg0;
  new_var = ((u8 *) var_a3) + 0x88;
  if (arg1 < (*((u16 *) (((u8 *) var_a3) + 0x88))))
  {
    var_v1 = (arg1 * (*((u16 *) (((u8 *) var_a3) + 0x8A)))) + (*((s32 *) (((u8 *) var_a3) + 0x4C)));
  }
  else
  {
    temp_a1 = arg1 - (*((u16 *) new_var));
    temp_a0 = *((void **) (((u8 *) var_a3) + 0x5C));
    temp_t0 = *((u16 *) (((u8 *) temp_a0) + 0x88));
    if (temp_a1 < temp_t0)
    {
      var_a3 = temp_a0;
      temp_a1 += 1;
      var_v1 = (*((s32 *) (((u8 *) var_a3) + 0x4C))) + (temp_a1 * (*((u16 *) (((u8 *) var_a3) + 0x8A))));
    }
    else
    {
      var_a3 = *((void **) (((u8 *) temp_a0) + 0x5C));
      temp_a1 = (temp_a1 - temp_t0) + 2;
      var_v1 = (temp_a1 * (*((u16 *) (((u8 *) var_a3) + 0x8A)))) + (*((s32 *) (((u8 *) var_a3) + 0x4C)));
    }
  }
  *((s32 *) arg2) = (*((s16 *) ((*((u8 **) (((u8 *) var_a3) + 0x54))) + (var_v1 * 6)))) + (*((s32 *) (((u8 *) var_a3) + 0x24)));
  *((s32 *) (((u8 *) arg2) + 4)) = (*((s16 *) (((*((u8 **) (((u8 *) var_a3) + 0x54))) + (var_v1 * 6)) + 2))) + (*((s32 *) (((u8 *) var_a3) + 0x28)));
  *((s32 *) (((u8 *) arg2) + 8)) = (*((s16 *) (((*((u8 **) (((u8 *) var_a3) + 0x54))) + (var_v1 * 6)) + 4))) + (*((s32 *) (((u8 *) var_a3) + 0x2C)));
}
