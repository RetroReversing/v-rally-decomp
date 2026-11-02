#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern f64 D_800A4150;
extern f64 D_800A4158;
extern u8 *D_800C7F84;
void func_8001BE68(u8 *, f32, f32, f32, f32 *, f32 *, f32 *);
void func_80014598(s32, s32, s32, s32, s32);
void func_80015168(s16 *arg0, s16 *arg1, s32 arg2)
{
  f32 sp20;
  f32 new_var;
  f32 sp24;
  f32 sp28;
  f32 sp2C;
  f32 sp30;
  f32 sp34;
  f32 fs0;
  f32 fs1;
  f32 fs2;
  f32 fa0;
  f32 fa1;
  f32 fa2;
  fa0 = (f32) arg0[0];
  fa1 = (f32) arg0[1];
  fa2 = (f32) arg0[2];
  fs0 = (f32) arg1[0];
  fs1 = (f32) arg1[1];
  fs2 = (f32) arg1[2];
  func_8001BE68(D_800C7F84 + 0xB8, fa0, fa1, fa2, &sp20, &sp24, &sp28);
  func_8001BE68(D_800C7F84 + 0xB8, fs0, fs1, fs2, &sp2C, &sp30, &sp34);
  if ((((f64) sp28) < D_800A4150) && (D_800A4158 < ((f64) sp28)))
  {
    if ((((f64) sp34) < D_800A4150) && (D_800A4158 < ((f64) sp34)))
    {
      f32 x0, y0, x1, y1;
      x0 = sp20 * 160.0f + 160.0f;
      y0 = -sp24 * 120.0f + 120.0f;
      x1 = sp2C * 160.0f + 160.0f;
      y1 = -sp30 * 120.0f + 120.0f;
      func_80014598((s32) x0, (s32) y0, (s32) x1, (s32) y1, arg2);
    }
  }
}

