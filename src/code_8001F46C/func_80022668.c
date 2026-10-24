#include "common.h"

void *func_80022668(void **arg0, s32 arg1)
{
  s32 var_a1;
  s32 var_v0;
  void *temp_v0;
  void *var_a0;
  var_a1 = arg1;
  var_a0 = *arg0;
  var_v0 = var_a1 != 0;
  goto loop_3;
  block_1:
  temp_v0 = *((void **) (((char *) var_a0) + 4));

  if (temp_v0 == NULL)
  {
    goto block_4;
  }
  var_a0 = temp_v0;
  var_a1 -= 1;
  ;
  loop_3:
  if ((var_a1 != 0) & (var_a0 != NULL))
  {
    goto block_1;
  }

  block_4:
  return var_a0;

}
