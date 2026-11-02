#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern f64 D_800A6D48;
extern f64 D_800A6D50;
extern f64 D_800A6D58;
extern f64 D_800A6D60;
extern f64 D_800A6D68;
extern f64 D_800A6D70;
extern f64 D_800A6D78;
extern f64 D_800A6D80;
extern f64 D_800A6D88;
extern f64 D_800A6D90;
extern f64 D_800A6D98;
extern f64 D_800A6DA0;
extern f64 D_800A6DA8;
extern f64 D_800A6DB0;
f32 func_80089300(f32 x)
{
  f32 x4;
  f32 x2;
  if (x == 0.0f)
  {
    return 1.0f;
  }
  if (x > 0.0f)
  {
    x2 = x * x;
    return x * D_800A6D80 + D_800A6DA0 + x2 * D_800A6D88 + (x2 * x) * D_800A6D90
         + (x2 * x2) * D_800A6D98 + ((x2 * x2) * x) * D_800A6DA8 + ((x2 * x2) * x2) * D_800A6DB0;
  }
  x = -x;
  x2 = x * x;
  x4 = x2 * x2;
  return D_800A6D68 / (x * D_800A6D48 + D_800A6D68 + x2 * D_800A6D50 + (x2 * x) * D_800A6D58
         + x4 * D_800A6D60 + (x4 * x) * D_800A6D70 + (x4 * x2) * D_800A6D78);
}
