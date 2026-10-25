#include "common.h"

f32 func_8001BFC4(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6)
{
  f32 *new_var;
  f32 new_var2;
  f32 temp_ft1;
  new_var2 = arg3;
  temp_ft1 = ((((*((f32 *) (((char *) arg0) + 0xC))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x1C))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x2C))) * new_var2)) + (*((f32 *) (((char *) arg0) + 0x3C)));
  if (temp_ft1 == 0.0f)
  {
    *arg4 = 0.0f;
    *arg5 = 0.0f;
    *arg6 = 0.0f;
    return 0.0f;
  }
  new_var = arg4;
  *new_var = (((*((f32 *) (((char *) arg0) + 0))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x10))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x20))) * arg3);
  *arg5 = (((*((f32 *) (((char *) arg0) + 4))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x14))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x24))) * arg3);
  *arg6 = (((*((f32 *) (((char *) arg0) + 8))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x18))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x28))) * arg3);
  if (temp_ft1 != 1.0f)
  {
    if (arg0)
    {
      *arg4 /= temp_ft1;
      *arg5 /= temp_ft1;
      *arg6 /= temp_ft1;
      return temp_ft1;
    }
    else
    {
      *arg4 /= temp_ft1;
      *arg5 /= temp_ft1;
      *arg6 /= temp_ft1;
      return temp_ft1;
    }
  }
  return 0.0f;
}
