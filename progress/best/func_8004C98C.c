#define sp48 rect.x
#define sp4A rect.y
#define sp4C rect.w
#define sp4E rect.h
void *func_800056FC();
s32 func_80006298(void *);
s32 func_800067FC(void *, s32, s16, s16);
s32 func_800070CC(void *);
s32 func_80007404(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_80008770(void *, void *, u8, u16 *);
s32 func_80008C58(void *, s32, u16, s32);
extern s32 D_800A11B8;
void func_8004C98C(void *arg0, void *arg1, void *arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8)
{
  struct 
  {
    u16 x;
    s16 y;
    u16 w;
    u16 h;
  } rect;
  u8 sp57;
  u8 sp5F;
  u8 sp67;
  u8 sp6F;
  u8 sp77;
  u8 sp7F;
  u8 sp87;
  u8 sp8F;
  u16 sp96;
  s32 sp9C;
  s32 spA4;
  s32 spAC;
  f32 temp_fs0;
  f32 temp_fs1;
  f32 temp_fv1;
  f32 temp_fv1_2;
  s32 var_s4;
  u16 temp_s0;
  s32 temp_s1;
  s32 temp_s2;
  s32 temp_s3;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 var_a0;
  u16 temp_v1_2;
  void *temp_s5;
  void *temp_v1;
  sp5F = arg6;
  sp67 = arg7;
  sp57 = arg3;
  sp6F = arg8;
  temp_s5 = func_800056FC(arg0);
  temp_v1 = *((void **) (((char *) temp_s5) + 0x14));
  sp77 = arg4;
  sp7F = arg5;
  *((s32 *) (((char *) temp_s5) + 0x14)) = (s32) (temp_v1 + 8);
  *((s32 *) (((char *) temp_v1) + 0)) = 0xDE000000;
  *((s32 **) (((char *) temp_v1) + 4)) = &D_800A11B8;
 do { if (arg8 == 0) { sp96 = *((u16 *) (((char *) arg1) + 8)); } else { sp96 = (u16) (((u16) (*((u16 *) (((char *) arg1) + 8)))) >> 1); } var_s4 = 0; temp_fs1 = ((f32) (*((s16 *) (((char *) arg2) + 6)))) / ((f32) sp96); if (sp96 != 0) { sp9C = (s32) sp96; spA4 = arg5 & 0xFF; spAC = arg4 & 0xFF; do { sp4A = var_s4; sp4C = *((u16 *) (((char *) arg1) + 6)); if (sp6F != 0) { sp48 = (u16) (((u16) (*((u16 *) (((char *) arg1) + 6)))) >> 1); } else { sp48 = 0; } temp_v1_2 = *((u16 *) (((char *) arg1) + 0xC)); if (var_s4 < (sp9C - temp_v1_2)) { sp4E = temp_v1_2; temp_v1_3 = var_s4 + (*((u16 *) (((char *) arg1) + 0xC))); temp_fv1 = ((f32) ((spA4 * (sp9C - temp_v1_3)) + (sp5F * temp_v1_3))) / ((f32) sp9C); var_a0 = (u32) temp_fv1; temp_v1_4 = var_s4 + (*((u16 *) (((char *) arg1) + 0xC))); temp_fv1_2 = ((f32) ((spAC * (sp9C - temp_v1_4)) + (sp67 * temp_v1_4))) / ((f32) sp9C); sp87 = (u8) var_a0; sp8F = (u32) temp_fv1_2; } else { sp4E = (sp96 - var_s4) + 1; sp87 = sp5F; sp8F = sp67; } func_80008770(temp_s5, arg1, sp57, &sp48); temp_s0 = func_800070CC(temp_s5); temp_fs0 = ((f32) var_s4) * temp_fs1; temp_s3 = temp_s0 & 0xFFFF; func_800067FC(temp_s5, temp_s3, *((s16 *) (((char *) arg2) + 0)), (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 2)))) + temp_fs0))); temp_s2 = (unsigned short)(temp_s0 + 1); func_800067FC(temp_s5, temp_s2, (s16) (((u16) (*((s16 *) (((char *) arg2) + 0)))) + (*((u16 *) (((char *) arg2) + 4)))), (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 2)))) + temp_fs0))); temp_s1 = (unsigned short)(temp_s0 + 2); func_800067FC(temp_s5, temp_s1, (s16) (((u16) (*((s16 *) (((char *) arg2) + 0)))) + (*((u16 *) (((char *) arg2) + 4)))), (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 2)))) + (((f32) (((s16) sp4E) + var_s4)) * temp_fs1)))); temp_s0 = (temp_s0 + 3) & 0xFFFF; func_800067FC(temp_s5, temp_s0, *((s16 *) (((char *) arg2) + 0)), (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 2)))) + (((f32) (((s16) sp4E) + var_s4)) * temp_fs1)))); func_80007404(temp_s5, temp_s3, 0xFF, 0xFF, 0xFF, (s32) sp77, 0xFF, 0xFF, 0xFF, (s32) sp7F, 0xFF, 0xFF, 0xFF, (s32) sp87, 0xFF, 0xFF, 0xFF, (s32) sp8F); func_80008C58(temp_s5, temp_s3, sp48, 0); func_80008C58(temp_s5, temp_s2, (sp4C - 1) & 0xFFFF, 0); func_80008C58(temp_s5, temp_s1, (sp4C - 1) & 0xFFFF, (sp4E - 1) & 0xFFFF); func_80008C58(temp_s5, temp_s0, sp48, (sp4E - 1) & 0xFFFF); sp77 = sp8F; sp7F = sp87; var_s4 += *((u16 *) (((char *) arg1) + 0xC)); } while (var_s4 < sp9C); } func_80006298(temp_s5); } while (0);
}
