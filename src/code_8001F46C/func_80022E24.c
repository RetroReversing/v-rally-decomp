#include "common.h"

void func_80022E24(void *arg0, s32 arg1)
{
  s32 var_a2;
  unsigned int new_var;
  void *temp_v0;
  void *var_v1;
  var_a2 = 0;
  if ((*((s32 *) (((char *) arg0) + 0xA0))) != (-1))
  {
    new_var = -1;
    var_v1 = arg0;
    do
    {
      var_v1 += 4;
      var_a2 += 1;
    }
    while ((*((s32 *) (((char *) var_v1) + 0xA0))) != new_var);
  }
  ;
  *((s32 *) (((char *) ((var_a2 * 4) + arg0)) + 0xA0)) = arg1;
  *((s32 *) (((char *) ((var_a2 * 4) + arg0)) + 0xA4)) = -1;
}
