#include "common.h"

extern f64 D_800A6D20;
void *func_80088258(void *arg0, u8 *arg1)
{
  double new_var;
  f32 temp_fv1;
  new_var = ((f64) ((f32) (*arg1))) * D_800A6D20;
  temp_fv1 = *((f32 *) (((char *) arg0) + 0x6C));
  *((f32 *) (((char *) arg0) + 0x20)) = (f32) (temp_fv1 * temp_fv1);
  *((f32 *) (((char *) arg0) + 0x68)) = (f32) new_var;
  return arg1 + 1;
}
