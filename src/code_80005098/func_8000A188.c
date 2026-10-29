#include "snapshot29_0433f7af8f6d.h"

typedef struct A188Src
{
  u8 pad00[4];
  u16 unk4;
  u16 unk6;
  u16 unk8;
  u8 pad0A[6];
  s32 *unk10;
  s32 *unk14;
} A188Src;
typedef struct A188Chain
{
  u8 pad00[4];
  A188Src **unk4;
} A188Chain;
typedef struct A188
{
  u8 pad00[0x0C];
  A188Chain *unkC;
  s16 unk10;
  s16 unk12;
  s16 unk14;
  s16 unk16;
  s16 unk18;
  s16 unk1A;
  s16 unk1C;
  s16 unk1E;
  s32 unk20;
  u16 unk24;
  u8 unk26;
  u8 unk27;
  s16 unk28;
  s16 unk2A;
  void *unk2C;
  u8 pad30[8];
  s32 unk38;
  s32 unk3C;
  s16 unk40;
  s16 unk42;
  s16 unk44;
  s16 unk46;
  s32 unk48;
  s32 unk4C;
} A188;
void osWritebackDCache(void *, s32);
void guS2DInitBg(void *, void *, s32);
void func_8000A188(A188 *arg0, A188 *arg1, s32 arg2, s32 arg3)
{
  A188Src *temp_a1;
  s32 *temp_a3;
  s32 temp_v1;
  arg0->unk2C = arg1;
  temp_a1 = *arg1->unkC->unk4;
  arg1->unk10 = 0;
  arg1->unk18 = 0;
  arg1->unk12 = temp_a1->unk6 * 4;
  arg1->unk1A = temp_a1->unk8 * 4;
  arg1->unk14 = 0;
  arg1->unk1C = 0;
  arg1->unk16 = temp_a1->unk6 * 4;
  arg1->unk1E = temp_a1->unk8 * 4;
  arg1->unk2A = 0;
  arg1->unk24 = 0xFFF4;
  arg1->unk28 = 0;
  temp_a3 = temp_a1->unk14 - (-((u8) arg3));
  arg1->unk20 = *temp_a3;
  temp_v1 = temp_a1->unk4;
  if ((u32)temp_v1 < 0x11)
  {
    arg1->unk26 = 2;
    arg1->unk27 = 0;
  }
  else
    if ((u32)temp_v1 < 0x101)
  {
    arg1->unk26 = 2;
    arg1->unk27 = 1;
  }
  else
  {
    arg1->unk26 = 0;
    arg1->unk27 = 2;
  }
  arg1->unk38 = 0x30;
  temp_v1 = temp_a1->unk10[(u8) arg2];
  arg1->unk40 = 0x100;
  arg1->unk3C = temp_v1;
  arg1->unk42 = temp_a1->unk4 + (-1);
  arg1->unk44 = 0;
  arg1->unk46 = 0;
  arg1->unk48 = temp_a1->unk10[(u8) arg2];
  arg1->unk4C = -1;
  guS2DInitBg(&arg1->unk10, temp_a1, arg2);
  osWritebackDCache(arg1, 0x50);
}
