#include "common.h"

s32 func_800056FC();
void *func_80006008();
s32 func_80006014();
void func_8000EB58(s32 arg0, s32 arg1, void *arg2)
{
  s32 temp_s0;
  s32 temp_v0;
  s32 temp_a0_2;
  s32 temp_v1_2;
  u8 *dl;
  s32 *temp_v0_2;
  s32 *temp_a2;
  int new_var;
  s32 *temp_a3;
  s32 *temp_t0;
  s32 *temp_a1;
  s32 *temp_a0;
  s32 *temp_v1;
  temp_v0 = func_800056FC();
  dl = func_80006008(temp_v0);
  temp_v1 = (s32 *) dl;
  dl += 8;
  temp_v1[0] = 0xE7000000;
  temp_v1[1] = 0;
  temp_a0 = (s32 *) dl;
  dl += 8;
  temp_a0[1] = 0x300000;
  temp_a0[0] = 0xE3000A01;
  temp_a1 = (s32 *) dl;
  dl += 8;
  temp_a1[0] = 0xFE000000;
  temp_s0 = arg1 - 0x80000000;
  temp_a1[1] = temp_s0;
  temp_a3 = (s32 *) dl;
  new_var = *((s16 *) (((u8 *) arg2) + 4));
  dl += 8;
  temp_t0 = (s32 *) dl;
  dl += 8;
  temp_a2 = (s32 *) dl;
  dl += 8;
  temp_a3[1] = temp_s0;
  temp_a3[0] = ((new_var - 1) & 0xFFF) | 0xFF100000;
  temp_t0[0] = 0xF7000000;
  temp_t0[1] = 0xFFFCFFFC;
  temp_a0_2 = (((*((s16 *) (((u8 *) arg2) + 4))) - 1) & 0x3FF) << 14;
  temp_v1_2 = ((((*((s16 *) (((u8 *) arg2) + 6))) - 1) & 0x3FF) << 2) | 0xF6000000;
  temp_a2[0] = temp_a0_2 | temp_v1_2;
  temp_a2[1] = (((*((u16 *) (((u8 *) arg2) + 0))) & 0x3FF) << 14) | (((*((u16 *) (((u8 *) arg2) + 2))) & 0x3FF) << 2);
  temp_v0_2 = (s32 *) dl;
  dl += 8;
  temp_v0_2[0] = 0xE7000000;
  temp_v0_2[1] = 0;
  func_80006014(temp_v0, dl, temp_a2, temp_a3);
}
