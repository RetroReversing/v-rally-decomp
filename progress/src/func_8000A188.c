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
/* Fills the background-layer header `bg` from the source sprite chain `owner->unkC`, choosing the
 * depth class from the source's unk4 size, then initialises the layer and writes its cache line back. */
void func_8000A188(A188 *owner, A188 *bg, s32 arg2, s32 arg3)
{
  A188Src *src;
  s32 *temp_a3;
  s32 temp_v1;
  owner->unk2C = bg;
  src = *bg->unkC->unk4;
  bg->unk10 = 0;
  bg->unk18 = 0;
  bg->unk12 = src->unk6 * 4;
  bg->unk1A = src->unk8 * 4;
  bg->unk14 = 0;
  bg->unk1C = 0;
  bg->unk16 = src->unk6 * 4;
  bg->unk1E = src->unk8 * 4;
  bg->unk2A = 0;
  bg->unk24 = 0xFFF4;
  bg->unk28 = 0;
  temp_a3 = src->unk14 - (-((u8) arg3));
  bg->unk20 = *temp_a3;
  temp_v1 = src->unk4;
  if ((u32)temp_v1 < 0x11)
  {
    bg->unk26 = 2;
    bg->unk27 = 0;
  }
  else
    if ((u32)temp_v1 < 0x101)
  {
    bg->unk26 = 2;
    bg->unk27 = 1;
  }
  else
  {
    bg->unk26 = 0;
    bg->unk27 = 2;
  }
  bg->unk38 = 0x30;
  temp_v1 = src->unk10[(u8) arg2];
  bg->unk40 = 0x100;
  bg->unk3C = temp_v1;
  bg->unk42 = src->unk4 + (-1);
  bg->unk44 = 0;
  bg->unk46 = 0;
  bg->unk48 = src->unk10[(u8) arg2];
  bg->unk4C = -1;
  guS2DInitBg(&bg->unk10, src, arg2);
  osWritebackDCache(bg, 0x50);
}
