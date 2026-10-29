#include "snapshot29_0433f7af8f6d.h"

u16 func_8000665C();
s32 func_80006CF8(void *arg0, s16 arg1)
{
  s32 var_a2;
  s32 temp_v0;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_a0_2;
  s32 temp_a0_3;
  void *temp_t0;
  void *temp_v1;
  int new_var;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_5;
  void *temp_v1_6;
  u16 flags;
  var_a2 = *((u16 *) (((char *) arg0) + 0x78));
  flags = var_a2;
  if (!(flags & 1))
  {
    temp_v1 = *((void **) (((char *) arg0) + 0x14));
    *((u16 *) (((char *) arg0) + 0x78)) = (u16) (flags | 1);
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1 + 8);
    *((s32 *) (((char *) temp_v1) + 0)) = 0xE7000000;
    *((s32 *) (((char *) temp_v1) + 4)) = 0;
    temp_v1_2 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_2 + 8);
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xE3000A01;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 0;
    temp_v1_3 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_3 + 8);
    *((s32 *) (((char *) temp_v1_3) + 0)) = 0xD7000000;
    *((s32 *) (((char *) temp_v1_3) + 4)) = 0;
    var_a2 = 0xFCFFFFFF;
    temp_v1_4 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_4 + 8);
    *((s32 *) (((char *) temp_v1_4) + 0)) = 0xFCFFFFFF;
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0xFFFE793C;
    temp_v1_5 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_5 + 8);
    *((s32 *) (((char *) temp_v1_5) + 0)) = 0xD9E0F9FA;
    *((s32 *) (((char *) temp_v1_5) + 4)) = 0;
    temp_v1_6 = *((void **) (((char *) arg0) + 0x14));
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_v1_6 + 8);
    *((s32 *) (((char *) temp_v1_6) + 0)) = 0xD9FFFFFF;
    *((s32 *) (((char *) temp_v1_6) + 4)) = 0x200005;
  }
  temp_v0 = func_8000665C(arg0, 4, var_a2) & 0xFFFF;
  temp_a0_2 = temp_v0 * 0x10;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 4)) = arg1;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x14)) = arg1;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x24)) = arg1;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x34)) = arg1;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 6)) = 0;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x16)) = 0;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x26)) = 0;
  *((s16 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x36)) = 0;
  *((u8 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xF)) = 0xFF;
  *((u8 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x1F)) = 0xFF;
  *((u8 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x2F)) = 0xFF;
  *((u8 *) (((char *) (temp_a0_2 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0x3F)) = 0xFF;
  temp_a2 = temp_v0 & 0x1F;
  temp_a3 = temp_a2 << 0x11;
  temp_t0 = *((void **) (((char *) arg0) + 0x14));
  new_var = temp_a3 | ((temp_a2 + 1) << 9);
  temp_a0_3 = temp_a2 + 2;
  temp_a0_3 = temp_a0_3 * 2;
  *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_t0 + 8);
  *((s32 *) (((char *) temp_t0) + 0)) = (s32) ((new_var | temp_a0_3) | 0x07000000);
  *((s32 *) (((char *) temp_t0) + 4)) = (s32) ((temp_a3 | (temp_a0_3 << 8)) | ((temp_a2 + 3) * 2));
  temp_a0_2 = *((void **) (((char *) arg0) + 0x14));
  *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_a0_2 + 8);
  *((s32 *) (((char *) temp_a0_2) + 0)) = 0xE7000000;
  *((s32 *) (((char *) temp_a0_2) + 4)) = 0;
  return temp_v0;
}
