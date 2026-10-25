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
s32 func_80006014(s32, s32 *);
s32 func_8008F1A0(s32);
void func_8000E9D4(s32 arg0, s32 arg1, A1564 *arg2, u8 *arg3)
{
  s32 *gfx;
  s32 *d0;
  s32 *d1;
  s32 *d2;
  s32 *d3;
  s32 *d4;
  s32 *d5;
  s32 temp_s6;
  s32 color;
  s32 temp_v0;
  s32 temp_v1;

  temp_s6 = func_800056FC();
  gfx = func_80006008(temp_s6);
  d0 = gfx;
  gfx += 2;
  d1 = gfx;
  gfx += 2;
  d0[0] = 0xE7000000;
  d0[1] = 0;
  d1[0] = 0xE3000A01;
  d1[1] = 0x300000;
  d2 = gfx;
  gfx += 2;
  d2[0] = ((arg2->unk4 - 1) & 0xFFF) | 0xFF100000;
  d2[1] = func_8008F1A0(arg1);
  d3 = gfx;
  gfx += 2;
  d3[0] = 0xF7000000;
  color = (((arg3[0] << 8) & 0xF800) | ((arg3[1] * 8) & 0x7C0)) | ((arg3[2] >> 2) & 0x3E);
  d3[1] = ((color | 1) << 16) | (1 | color);
  d4 = gfx;
  gfx += 2;
  temp_v1 = ((arg2->unk4 - 1) & 0x3FF) << 14;
  temp_v0 = ((arg2->unk6 - 1) & 0x3FF) * 4;
  temp_v0 = temp_v0 | 0xF6000000;
  d4[0] = temp_v1 | temp_v0;
  d4[1] = ((arg2->unk0 & 0x3FF) << 14) | ((arg2->unk2 & 0x3FF) * 4);
  d5 = gfx;
  gfx += 2;
  d5[0] = 0xE7000000;
  d5[1] = 0;
  func_80006014(temp_s6, gfx);
}
