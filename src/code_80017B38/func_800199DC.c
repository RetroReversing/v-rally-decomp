#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
s32 func_8000665C();
s32 func_800068C0();
s32 func_800199DC(void *arg0, void *arg1, void *arg2)
{
  f32 sp[3];
  s32 temp_s0;
  void *temp_t0;
  s32 temp_a2;
  char *new_var;
  s16 new_var2;
  int new_var3;
  s32 temp_a3;
  unsigned char temp_a0;
  sp[0] = ((*((f32 *) (((char *) arg1) + 0x110))) * ((f32) (*((u16 *) (((char *) arg2) + 0x14))))) * 0.5f;
  new_var3 = 4;
  sp[2] = ((*((f32 *) (((char *) arg1) + 0x118))) * ((f32) (*((u16 *) (((char *) arg2) + 0x14))))) * 0.5f;
  sp[1] = (f32) (*((u16 *) (((char *) arg2) + 0x16)));
  temp_s0 = func_8000665C(arg0, new_var3);
  temp_s0 = temp_s0 & 0xffff;
  arg1 = arg1;
  new_var = (char *) arg2;
  new_var2 = (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 8)))) - sp[2]));
  func_800068C0(arg0, temp_s0, (s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 4)))) - sp[0])), *((s16 *) (((char *) arg2) + 6)), (s32) new_var2, (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 4)))) - sp[0]))), (s32) ((s16) (((u16) (*((s16 *) (((char *) arg2) + 6)))) - (*((u16 *) (((char *) arg2) + 0x16))))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 8)))) - sp[2]))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 4)))) + sp[0]))), (s32) ((s16) (((u16) (*((s16 *) (((char *) arg2) + 6)))) - (*((u16 *) (((char *) arg2) + 0x16))))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 8)))) + sp[2]))), (s32) ((s16) ((s32) (((f32) (*((s16 *) (((char *) arg2) + 4)))) + sp[0]))), *((s16 *) (((char *) arg2) + 6)), (s32) ((s16) ((s32) (((f32) (*((s16 *) (new_var + 8)))) + sp[2]))));
  temp_t0 = *((void **) (((char *) arg0) + 0x14));
  temp_a2 = temp_s0 & 31;
  temp_a3 = temp_a2 << 17;
  *((void **) (((char *) arg0) + 0x14)) = temp_t0 + 8;
  *((s32 *) temp_t0) = ((temp_a3 | ((temp_a2 + 1) << 9)) | ((u8)((temp_a2 + 2) * 2))) | 0x07000000;
  *((s32 *) (((char *) temp_t0) + 4)) = (temp_a3 | (((u8)((temp_a2 + 2) * 2)) << 8)) | ((temp_a2 + 3) * 2);
  return temp_s0;
}

