#include "common.h"

void *func_80022318();
s32 func_80022374(s32 arg0, s32 arg1, s32 arg2)
{
  void *temp_v0;
  temp_v0 = func_80022318();
  if (temp_v0 == NULL)
  {
    return 0;
  }
  if (temp_v0)
  {
    *((s32 *) (((char *) (*((void **) (((char *) temp_v0) + 0x10)))) + 8)) = arg2;
    return 1;
  }
  else
  {
    *((s32 *) (((char *) (*((void **) (((char *) temp_v0) + 0x10)))) + 8)) = arg2;
    return 1;
  }
}
