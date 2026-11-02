#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define sp20 matrix.matrix
#define sp50 matrix.translate
s32 func_80010BFC();
s32 func_8001BE68(void *, f32, s32, f32, f32 *, f32 *, s32 *);
s32 func_8002D2C8();
s32 func_8002E688();
s32 guMtxIdentF();
void func_800480B0(void *arg0, void *arg1)
{
  s32 *new_var2;
  struct 
  {
    s32 matrix[12];
    f32 translate[4];
  } matrix;
  s32 sp60[4];
  int new_var3;
  char *new_var;
  f32 sp70;
  float new_var4;
  f32 sp74;
  u32 sp78;
  f32 temp_fv1;
  f32 temp_ft0f;
  f32 temp_fv0f;
  s32 temp_ft0;
  s32 temp_fv0;
  guMtxIdentF(sp20);
  sp50[0] = *((f32 *) (((char *) arg0) + 0x118));
  sp50[1] = *((f32 *) (((char *) arg0) + 0x11C));
  sp50[2] = *((f32 *) (((char *) arg0) + 0x120));
  func_80010BFC(0, arg0 + 0x38, sp20);
  ;
  *((s32 *) (((char *) arg1) + 0x88)) = (s32) (((s32) (-(*((f32 *) (((char *) arg0) - -0x108))))) & 0xFFF);
  new_var4 = (*((f32 *) (((char *) arg0) + 0x124))) - (*((f32 *) (((char *) arg0) + 0x118)));
  temp_ft0f = new_var4;
  new_var = ((char *) arg0) + 0x12C;
  temp_fv0f = *((f32 *) new_var);
  temp_fv0f = temp_fv0f - (*((f32 *) (((char *) arg0) + 0x120)));
  sp60[1] = 0;
  temp_ft0 = (s32) temp_ft0f;
  temp_fv0 = (s32) temp_fv0f;
  new_var3 = 0;
  sp60[new_var3] = temp_ft0;
  sp60[2] = temp_fv0;
  func_8002E688(&sp60[new_var3], &sp60[0]);
  {
    f32 fb = (f32) sp60[2];
    func_8001BE68(arg0 + 0xB8, (f32) sp60[new_var3], new_var3,
    fb, &sp70, &sp74, &sp78);
  }
  sp70 *= 114.0f;
  temp_fv1 = sp74; temp_fv1 = (sp74 = temp_fv1 * 114.0f);
  if (temp_fv1 < (-500.0f))
  {
    sp74 = -500.0f;
  }
  if (sp74 > 500.0f)
  {
    sp74 = 500.0f;
  }
  *((s32 *) (((char *) arg1) + 0x7C)) = (s32) sp74;
  *((s16 *) (((char *) arg1) + 0x10)) = (s16) (-(((func_8002D2C8(temp_fv0, temp_ft0) * 2) / 3) & 0xFFF));
}

