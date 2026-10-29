#include "snapshot29_0433f7af8f6d.h"

#define sp78 output[0]
#define sp7C output[1]
#define sp80 output[2]
#define sp88 scale[0]
#define sp90 scale[2]
void *func_80006008(s32);
s32 func_80006014(s32, s32);
s32 func_800061FC(s32, s32);
s32 func_800068C0(s32, s32, s16, s16, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80006CF8(s32, s32);
s32 func_800071EC(s32, s32, u8, u8, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80010BFC(s32, void *, void *);
s32 func_8001BD1C();
f32 func_8001BE68(void *, f32, f32, f32, f32 *, f32 *, f32 *);
s32 func_8003647C(s16 *, s32);
s32 guMtxIdentF(void *);
extern s32 D_8009F5F8;
extern void *D_800C7F84;
extern void *D_800C811C;
void func_8003678C(s16 *arg0, s32 arg1, u8 arg2)
{
  s32 reject_y;
  f32 sp38[16];
  f32 output[4];
  volatile f32 scale[4];
  f32 temp_ft0;
  f32 temp_fv0;
  f32 temp_fv1;
  s16 temp_a2;
  s32 temp_s0;
  s32 temp_v0;
  s32 temp_v0_3;
  char *new_var;
  s32 var_s3;
  s32 var_s5;
  void *temp_v0_2;

  guMtxIdentF(&sp38);
  var_s5 = 0;
  temp_v0 = func_8001BD1C();
  sp38[12] = *((f32 *) (((char *) D_800C7F84) + 0x118));
  sp38[13] = *((f32 *) (((char *) D_800C7F84) + 0x11C));
  sp38[14] = *((f32 *) (((char *) D_800C7F84) + 0x120));
  func_80010BFC(temp_v0, D_800C7F84 + 0x38, &sp38);
  func_8003647C(arg0, arg2 & 0xFF);
  temp_v0_2 = func_80006008(arg1);
  *((s32 *) (((char *) temp_v0_2) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v0_2) + 4)) = &D_8009F5F8;
  func_80006014(arg1, temp_v0_2 + 8);
  var_s3 = *((s32 *) (((char *) D_800C811C) + 8));
  new_var = ((char *) arg0) + 15;
  if ((var_s3--) != 0)
  {
    reject_y=0x3E9;
    do
    {
      temp_a2 = *((s16 *) (((char *) arg0) + 2));
      if ((((((((temp_a2 != 0) && ((temp_fv0 = func_8001BE68(D_800C7F84 + 0xB8, (f32) (*arg0), (f32) temp_a2, (f32) (*((s16 *) (((char *) arg0) + 4))), &sp78, &sp7C, &sp80), sp78 < 1.0f))) && (sp78 > (-1.0f))) && (sp7C < 1.0f)) && (sp7C > (-1.0f))) && (sp80 < 1.0f)) && (sp80 > (-1.0f))) && (((f64) temp_fv0) >= 0.0))
      {
        if (!(var_s5 & 0xFF))
        {
          var_s5 = 1;
          func_800061FC(arg1, temp_v0);
        }
        temp_v0_3 = func_80006CF8(arg1, 0);
        temp_ft0 = *((f32 *) (((char *) D_800C7F84) + 0x148));
        sp88 = temp_ft0;
        temp_fv1 = *((f32 *) (((char *) D_800C7F84) + 0x150));
        sp90 = temp_fv1;
        temp_s0 = temp_v0_3 & 0xFFFF;
        func_800068C0(arg1, temp_s0, (s16) ((s32) (((f32) (*arg0)) - temp_ft0)), *((s16 *) (((char *) arg0) + 2)), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg0) + 4)))) - temp_fv1))), (s32) ((s16) ((s32) ((((f32) (*arg0)) - sp88) + 2.0f))), (s32) ((s16) (((u16) (*((s16 *) (((char *) arg0) + 2)))) + 2)), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) arg0) + 4)))) - sp90) + 2.0f))), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) arg0) + 6)))) + sp88) + 1.0f))), (s32) ((s16) ((*((u16 *) (((char *) arg0) + 8))) + 1)), (s32) ((s16) ((s32) ((((f32) (*((s16 *) (((char *) arg0) + 10)))) + sp90) + 1.0f))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg0) + 6)))) + sp88))), (s32) ((s16) (*((u16 *) (((char *) arg0) + 8)))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg0) + 10)))) + sp90))));
        func_800071EC(arg1, temp_s0, *((u8 *) (((char *) arg0) + 13)), *((u8 *) (((char *) arg0) + 14)), (s32) (*((u8 *) (((char *) arg0) + 15))), (s32) (*((u8 *) (((char *) arg0) + 13))), (s32) (*((u8 *) (((char *) arg0) + 14))), (s32) (*((u8 *) (((char *) arg0) + 15))), (s32) (*((u8 *) (((char *) arg0) + 16))), (s32) (*((u8 *) (((char *) arg0) + 17))), (s32) (*((u8 *) (((char *) arg0) + 18))), (s32) (*((u8 *) (((char *) arg0) + 13))), (s32) (*((u8 *) (((char *) arg0) + 17))), (s32) (*((u8 *) (((char *) arg0) + 18))));
      }
      else
      {
        *((s16 *) (((char *) arg0) + 2)) = (s16) reject_y;
      }
      arg0 += 0xA;
    }
    while ((var_s3--) != 0);
  }
}
