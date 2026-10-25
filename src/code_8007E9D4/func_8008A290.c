#include "common.h"

void func_8008A290(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  char *var_a1;
  s32 var_t0;
  s32 new_var2;
  void *temp_t1;
  char *new_var;
  void *var_a0;
  temp_t1 = (*((s32 *) (((char *) arg0) + 0x10))) + ((arg1 & 0xFFFF) * 0x14);
  new_var2 = arg2;
  var_a1 = *((char **) (((char *) temp_t1) + 4));
  var_t0 = 0;
  if ((*((u8 *) (((char *) temp_t1) + 0xF))) == 0)
  {
    goto block_10;
  }
  var_a0 = var_a1;
  var_a0 = var_a0 + 8;
  loop_2:
  if ((*(s32 *)var_a1) == new_var2)
  {
    goto block_4;
  }

  var_t0 += 1;
  goto block_9;
  new_var = (char *) var_a0;
  block_4:
  if ((*((s8 *) (((char *) var_a0) + (-4)))) == 0)
  {
    goto block_7;
  }

  var_t0 += 1;
  goto block_9;
  block_7:
  *((s32 *) (((char *) var_a0) + 0)) = arg3;

  return;
  block_9:
  var_a0 += 0xC;

  var_a1 += 0xC;
  if (((u32) (var_t0 & 0xFFFF)) < ((u8) (*((u8 *) (((char *) temp_t1) + 0xF)))))
  {
    goto loop_2;
  }
  block_10:
  return;

}
