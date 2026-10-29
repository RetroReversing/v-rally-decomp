#include "snapshot29_0433f7af8f6d.h"

s32 func_8002D2C8();
extern f64 D_800A48E0;
extern f64 D_800A48E8;
extern f64 D_800A48F0;
extern f64 D_800A48F8;

s32 func_8001FD14(void *arg0)
{
  f64 new_var;
  s32 s0;
  s32 a0;
  s32 t;
  s32 v1;
  s32 v0;
  f32 fv1;
  f32 __repair_fv1_1;
  f32 fs0;
  f32 fs1;

  fs0 = 100.0f;
  fs1 = 0.0f;
  s0 = func_8002D2C8(*((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x50)), *((s16 *) (((char *) (*((void **) (((char *) arg0) + 0x5C)))) + 0x44)));
  a0 = func_8002D2C8(*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x58)))) + 0x28)), *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x58)))) + 0x20)));
  fv1 = (f32) (*((s32 *) (*((void **) (((char *) arg0) + 0x58)))));
  if (fv1 < 2400.0f)
  {
    if (!(fv1 < 1200.0f))
    {
      t = (s32) fv1;
      if (t < 0)
      {
        t = -t;
      }
      __repair_fv1_1 = (f32) (0x960 - t);
      fs0 = (f32) ((((f64) (__repair_fv1_1 * 0.00083333335f)) * D_800A48E0) + D_800A48E8);
      fs1 = (f32) (D_800A48F0 - ((f64) fs0));
    }
  }
  else
  {
    fs0 = 25.0f;
    fs1 = 75.0f;
  }
  v1 = -0x400;
  v1 = s0 < v1;
  if (v1 && (a0 >= 0x401))
  {
    s0 += 0x1000;
  }
  if ((a0 < (-0x400)) && (s0 >= 0x401))
  {
    a0 += 0x1000;
  }
  s0 = (s32) (((f64) ((fs0 * ((f32) s0)) + (fs1 * ((f32) a0)))) * D_800A48F8);
  v0 = *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x58)))) + 8));
  return v0 - s0;
}
