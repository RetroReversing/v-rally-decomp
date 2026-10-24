#include "common.h"

void func_80022E64(void *arg0)
{
  int new_var2;
  s32 var_a0;
  char *new_var;
  void *var_s0;
  var_a0 = *((s32 *) (((char *) arg0) + 0xA0));
  if (var_a0 != (-1))
  {
    new_var2 = -1;
    var_s0 = arg0;
    do
    {
      new_var = (char *) arg0;
      var_s0 += 4;
      (*((s32 (**)(void *)) (((char *) ((var_a0 * 0x1C) + (*((s32 *) (new_var + ((unsigned long) 0xD0)))))) + 0x18)))(arg0);
      var_a0 = *((s32 *) (((char *) var_s0) + 0xA0));
    }
    while (var_a0 != new_var2);
  }
}
