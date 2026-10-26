#include "common.h"

extern f64 D_800A7208;
extern f64 D_800A7210;
extern f64 D_800A7218;
f32 _doModFunc(void *arg0, s32 arg1)
{
  f32 var_ft0;
  f64 new_var;
  f32 var_fv1;
  f64 temp_ft0;
  var_fv1 = (*((f32 *) (((char *) arg0) + 0x14))) + ((*((f32 *) (((char *) arg0) + 0x10))) * ((f32) arg1));
  temp_ft0 = (f64) var_fv1;
  new_var = D_800A7208;
  *((f32 *) (((char *) arg0) + 0x14)) = var_fv1;
  if (new_var < temp_ft0)
  {
    var_fv1 = (f32) (temp_ft0 - D_800A7210);
  }
  var_ft0 = var_fv1;
  *((f32 *) (((char *) arg0) + 0x14)) = var_fv1;
  if (var_fv1 < 0.0f)
  {
    var_ft0 = -var_fv1;
  }
  var_fv1 = ((f64) var_ft0) - D_800A7218;
  return (*((f32 *) (((char *) arg0) + 0x1C))) * ((f32) var_fv1);
}
