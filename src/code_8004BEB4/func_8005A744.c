#include "common.h"

s32 *func_8005A744(s32 arg0, s32 *arg1)
{
  s32 var_v0;
  var_v0 = arg0;
  goto check;
  loop:
  arg1 = *arg1;
  var_v0 = arg0;
  check:
  if (arg0-- != 0)
  {
    goto loop;
  }
  return arg1;
}
