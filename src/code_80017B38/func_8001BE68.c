#include "snapshot29_0433f7af8f6d.h"

f32 func_8001BE68(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5, f32 *arg6)
{
  f32 temp_ft1;
  temp_ft1 = ((((*((f32 *) (((char *) arg0) + 0xC))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x1C))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x2C))) * arg3)) + (*((f32 *) (((char *) arg0) + 0x3C)));
  if (temp_ft1 == 0.0f)
  {
    *arg4 = 0.0f;
    *arg5 = 0.0f;
    *arg6 = 0.0f;
    return 0.0f;
  }
  *arg4 = ((((*((f32 *) (((char *) arg0) + 0))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x10))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x20))) * arg3)) + (*((f32 *) (((char *) arg0) + 0x30)));
  *arg5 = ((((*((f32 *) (((char *) arg0) + 4))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x14))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x24))) * arg3)) + (*((f32 *) (((char *) arg0) + 0x34)));
  *arg6 = ((((*((f32 *) (((char *) arg0) + 8))) * arg1) + ((*((f32 *) (((char *) arg0) + 0x18))) * arg2)) + ((*((f32 *) (((char *) arg0) + 0x28))) * arg3)) + (*((f32 *) (((char *) arg0) + 0x38)));
  if (temp_ft1 == 1.0f) return 0.0f;

  {
 do { *arg4 /= temp_ft1; *arg5 /= temp_ft1; *arg6 /= temp_ft1; return temp_ft1; } while (0);
  }
}
