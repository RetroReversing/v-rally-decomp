#include "common.h"

typedef struct A1564
{
  u16 unk0;
  u16 unk2;
  s16 unk4;
  s16 unk6;
} A1564;
s32 func_800056FC();
s32 *func_80006008(s32);
s32 func_80006014(s32, s32 *, s32 *, s32 *);
void func_8000EF0C(s32 arg0, A1564 *arg1, u8 *arg2)
{
  s32 *d0;
  s32 *d1;
  s32 *d2;
  s32 *d3;
  s32 *d4;
  s32 *d5;
  s32 *gfx;
  s32 temp_s2;
  s32 color;
  s32 temp_v1;
  s32 temp_a0;
  temp_s2 = func_800056FC();
  gfx = func_80006008(temp_s2);
  d0 = gfx;
  gfx += 2;
  d1 = gfx;
  gfx += 2;
  d0[0] = 0xE7000000;
  d0[1] = 0;
  d1[1] = 0x300000;
  d1[0] = 0xE3000A01;
  d2 = gfx;
  gfx += 2;
  d2[0] = 0xF7000000;
  color = (((arg2[0] << 8) & 0xF800) | ((arg2[1] * 8) & 0x7C0)) | ((arg2[2] >> 2) & 0x3E);
  d3 = gfx;
  gfx += 2;
  d2[1] = ((color | 1) << 16) | (1 | color);
  d4 = gfx;
  gfx += 2;
  temp_a0 = ((arg1->unk4 - 1) & 0x3FF) << 14;
  temp_v1 = (((arg1->unk6 - 1) & 0x3FF) * 4) | 0xF6000000;
  color = temp_a0 | temp_v1;
  d3[0] = color;
  d3[1] = ((arg1->unk0 & 0x3FF) << 14) | ((arg1->unk2 & 0x3FF) * 4);
  d4[0] = 0xE7000000;
  d4[1] = 0;
  d5 = gfx;
  d5[0] = 0xE3000A01;
  d5[1] = 0;
  func_80006014(temp_s2, d5 + 2, d4, d3);
}
