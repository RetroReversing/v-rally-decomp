#include "snapshot29_0433f7af8f6d.h"

extern s32 D_8009B974;
extern s32 D_800A1634;
extern s32 D_800C35A0;
extern s32 func_80084F6C();
extern s32 func_800852FC(s32, s32 *, s32);
void func_80069424(void)
{
  int new_var;
  s8 i;
  s8 idx;
  s32 base;
  s32 charBase;
  s32 value;
  s8 j;
  u32 bits;
  s32 outIndex;
  i = 0;
  charBase = D_800C35A0 + 0x32;
  do
  {
    idx = i;
    base = D_800C35A0;
    value = *((u8 *) (charBase + idx));
    new_var = base + (value * 0x28);
    bits = *((u32 *) (new_var + 0x68));
    j = 0;
    do
    {
      outIndex = j << 24;
      *((s32 *) (((char *) (&D_8009B974)) + (outIndex >> 21))) = *((s32 *) (((char *) (&D_800A1634)) + ((bits & 0xF) * 4)));
      bits >>= 4;
      j = (s8) (j + 1);
    }
    while (j < 8);
    func_80084F6C(i & 0xFF);
    func_800852FC(i & 0xFF, &D_8009B974, 0xC);
    i = (s8) (i + 1);
  }
  while (i < 2);
}
