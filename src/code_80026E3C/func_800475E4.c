#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
#define sp60 rect.x
#define sp62 rect.y
#define sp64 rect.w
#define sp66 rect.h
void *func_800056FC(void *);
void *func_80006008(void *);
s32 func_80006014(void *, void *);
s32 func_800061FC(void *, s32);
s32 func_800067FC(void *, s32, s16, s16);
s32 func_80006984(void *, s32, s32, s32, s32);
u16 func_800070CC(void *);
s32 func_80008770(void *, void *, s32, s16 *);
s32 func_80008C58(void *, s32, s32, s32);
s32 func_8001BD1C();
s32 guMtxF2L(void *, s32);
s32 guMtxIdent(void *);
s32 guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
extern void *D_8009B5A4;
extern s32 D_800A0310;
extern s16 D_800A0370[];
extern s16 D_800A0372;
extern s16 D_800A0374;
extern s16 D_800A0376;
extern char D_800C02AE[];
void func_800475E4(void *arg0, void *arg1)
{
  f32 sp20[4][4];
  struct 
  {
    s16 x;
    s16 y;
    u16 w;
    u16 h;
    s32 extra[2];
  } rect;
  f32 temp_fs0;
  s32 var_s5;
  s32 temp_fv1;
  s32 temp_s0_2;
  u32 temp_s0_3;
  int temp_s1;
  u32 temp_s2;
  s32 temp_s3;
  u16 temp_a0;
  u16 temp_v1;
  u16 temp_v1_2;
  void *temp_a1;
  void *temp_a2;
  void *bounds;
  void *temp_s0;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  u32 command;
  u32 temp_v3;
  struct Packet
  {
    u32 w0;
    u32 w1;
  } *cursor;
  struct Packet *pkt;
  temp_s0 = D_800C02AE + 0x80D2;
  guMtxIdent(temp_s0);
  temp_v0 = func_800056FC(arg0);
  cursor = func_80006008(temp_v0);
  pkt = cursor++;
  command = 0xDA380003;
  pkt->w0 = 0xDE000000;
  pkt->w1 = (u32) (&D_800A0310);
  cursor->w0 = command;
  cursor->w1 = (u32) temp_s0;
  cursor++;
  func_80006014(temp_v0, cursor);
  var_s5 = 0;
  temp_s0_2 = func_8001BD1C();
  guOrthoF(sp20, 0, (f32) (*((s16 *) (((char *) arg0) + 0xC))), (f32) (*((s16 *) (((char *) arg0) + 0xE))), 0, -1.0f, 10.0f, 1.0f);
  guMtxF2L(sp20, temp_s0_2);
  func_800061FC(temp_v0, temp_s0_2);
  temp_a1 = *((void **) (((char *) temp_v0) + 0x14));
  *((void **) (((char *) temp_v0) + 0x14)) = (void *) (temp_a1 + 8);
  *((s32 *) (((char *) temp_a1) + 0)) = (0xED000000 | ((((s32) (((f32) D_800A0370[0]) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) D_800A0372) * 4.0f)) & 0xFFF);
  *((s32 *) (((char *) temp_a1) + 4)) = (s32) (((((s32) (((f32) ((D_800A0370[0] + D_800A0374) - 1)) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) ((D_800A0372 + D_800A0376) - 1)) * 4.0f)) & 0xFFF));
  temp_v1 = *((u16 *) (((char *) arg1) + 8));
  temp_fs0 = ((f32) (*((s16 *) (((char *) arg0) + 0xE)))) / ((f32) temp_v1);
  if (temp_v1 != 0)
  {
    do
    {
      sp60 = 0;
      sp62 = var_s5;
      sp64 = *((u16 *) (((char *) arg1) + 6));
      temp_a0 = *((u16 *) (((char *) arg1) + 8));
      temp_v1_2 = *((u16 *) (((char *) arg1) + 0xC));
      if (var_s5 < (temp_a0 - temp_v1_2))
      {
        sp66 = temp_v1_2;
      
      func_80008770(temp_v0, arg1, 0, &sp60);}
      else
      {
        sp66 = temp_a0 - var_s5;
      
      func_80008770(temp_v0, arg1, 0, &sp60);}
      temp_s1 = func_800070CC(temp_v0) & 0xFFFF;
      temp_s3 = temp_s1 & 0xFFFF;
      temp_fv1 = (s32) (((f32) var_s5) * temp_fs0);
      func_800067FC(temp_v0, temp_s3, 0, (s16) temp_fv1);
      temp_s2 = (u16) (temp_s1 + 1);
      func_800067FC(temp_v0, temp_s2, *((s16 *) (((char *) arg0) + 0xC)), (s16) temp_fv1);
      temp_s0_3 = (u16) (temp_s1 + 2);
      func_800067FC(temp_v0, temp_s0_3, *((s16 *) (((char *) arg0) + 0xC)), (s16) ((s32) (((f32) (((s16) sp66) + var_s5)) * temp_fs0)));
      ;
      temp_v3 = (u16)(temp_s1 + 3);
      func_800067FC(temp_v0, temp_v3, 0, (s16) ((s32) (((f32) (((s16) sp66) + var_s5)) * temp_fs0)));
      func_80008C58(temp_v0, temp_s3, 0, 0);
      func_80008C58(temp_v0, temp_s2, (sp64 - 1) & 0xFFFF, 0);
      func_80008C58(temp_v0, temp_s0_3, (sp64 - 1) & 0xFFFF, (sp66 - 1) & 0xFFFF);
      func_80008C58(temp_v0, temp_v3, 0, (sp66 - 1) & 0xFFFF);
      func_80006984(temp_v0, temp_s3, 0xFF, 0xFF, 0xFF);
      func_80006984(temp_v0, temp_s2, 0xFF, 0xFF, 0xFF);
      func_80006984(temp_v0, temp_s0_3, 0xFF, 0xFF, 0xFF);
      func_80006984(temp_v0, temp_v3, 0xFF, 0xFF, 0xFF);
      var_s5 += *((u16 *) (((char *) arg1) + 0xC));
    }
    while (var_s5 < ((s32) (*((u16 *) (((char *) arg1) + 8)))));
  }
  bounds = D_8009B5A4;
  temp_a2 = *((void **) (((char *) temp_v0) + 0x14));
  *((void **) (((char *) temp_v0) + 0x14)) = (void *) (temp_a2 + 8);
  *((s32 *) (((char *) temp_a2) + 0)) = (0xED000000 | ((((s32) (((f32) (*((s16 *) (((char *) bounds) + 0)))) * 4.0f)) & 0xFFF) << 12)) | (((s32) (((f32) (*((s16 *) (((char *) bounds) + 2)))) * 4.0f)) & 0xFFF);
  *((s32 *) (((char *) temp_a2) + 4)) = (s32) (((((s32) (((f32) (((*((s16 *) (((char *) bounds) + 0))) + (*((s16 *) (((char *) bounds) + 4)))) - 1)) * 4.0f)) & 0xFFF) << 0xC) | (((s32) (((f32) (((*((s16 *) (((char *) bounds) + 2))) + (*((s16 *) (((char *) bounds) + 6)))) - 1)) * 4.0f)) & 0xFFF));
}


