#include "common.h"

void func_8002F9EC(void *arg0, s32 arg1)
{
  s32 var_v0;
  void *var_a0;
  var_a0 = arg0;
  arg1 = arg1;
  var_v0 = arg1;
  goto loop_2;
  block_1:
  *((s32 *) (((char *) var_a0) + 0x20)) = 0;

  var_a0 += 0x24;
  var_v0 = arg1;
  loop_2:
  arg1 -= 1;

  if (var_v0 != 0)
  {
    goto block_1;
  }
  return;
}
