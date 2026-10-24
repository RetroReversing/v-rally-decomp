#include "common.h"

void *func_80010344();
void *func_800801D0();
void func_800103AC(s32 arg0, s32 arg1)
{
  u32 var_v1;
  unsigned int new_var;
  void *temp_v0;
  void *var_s0;
  temp_v0 = func_80010344(arg1 + 0xE4);
  if (temp_v0 == NULL)
  {
    goto block_3;
  }
  var_s0 = func_800801D0(arg0, 0x90);
  *((s32 *) (((char *) var_s0) + 0xC)) = (s32) (*((s32 *) (((char *) temp_v0) + 8)));
  *((s32 *) (((char *) var_s0) + 0x6C)) = arg0;
  (*((s32 (**)(void *, s32)) (((char *) temp_v0) + 4)))(var_s0, arg1);
  var_v1 = 0;
  loop_2:
  var_v1 += 1;

  *((s32 *) (((char *) var_s0) + 0x20)) = (s32) (new_var = *((s32 *) (((char *) var_s0) + 0x10)));
  var_s0 += 4;
  if (var_v1 < 4U)
  {
    goto loop_2;
  }
  block_3:
  return;

}
