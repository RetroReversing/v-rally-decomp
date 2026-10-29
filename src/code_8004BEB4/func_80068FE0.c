#include "snapshot29_0433f7af8f6d.h"

s32 func_80034FF0(s32, s32);
void *func_800592AC(s32);
void *func_800592D0(s32);
s32 func_800592F4(s32, s32);
s32 func_80081540(void *);
s32 func_8008A0D8(s32, s32, s32);
extern void *D_800A1468;
extern s32 D_800A1658[];
extern s8 D_800A167C[];
extern s8 D_800A1684[];
extern s32 D_800A57A4;
extern char D_800AE850[];
extern void *D_800C3508;
extern void *D_800C35A0;
void func_80068FE0(void)
{
  void *rec;
  s16 sh_val;
  s32 idx;
  void *row;
  s32 flag;
  void *obj;
  s32 i;
  s32 idx8;
  u32 bits;
  rec = func_800592D0(0);
  sh_val = 3;
  if ((*(((s8 *) D_800A1468) + 0x228)) != 0)
  {
    sh_val = 0x98;
  }
  *(((s16 *) rec) + 2) = sh_val;
  idx = *(((s8 *) D_800A1468) + 0x22A);
  row = ((char *) D_800C35A0) + (idx * 0x28);
  if (((*(((u8 *) row) + 0x48)) & 0x10) != 0)
  {
    func_8008A0D8((s32) D_800C3508, 0x17, 0);
    obj = func_800592AC(6);
    *(((s8 *) obj) + 0xF) = 0x50;
    *(((s8 *) obj) + 0x10) = 0x50;
    *(((s8 *) obj) + 0x11) = 0x50;
    func_800592F4(0x19, 1);
  }
  else
  {
    func_800592F4(0x19, 0);
  }
  i = 0;
  func_80081540(&D_800A57A4);
  do
  {
    idx8 = i & 0xFF;
    ((s32 *) (D_800AE850 + 0x87F8))[idx8] = func_80034FF0(D_800A1658[idx8], 0);
    i += 1;
  }
  while (((u32) (i & 0xFF)) < 9U);
  i = 0;
  idx = *(((s8 *) D_800A1468) + 0x22A);
  row = (char *) D_800C35A0;
  row = row + (idx * 0x28);
  bits = *((u32 *) (((char *) row) + 0x68));
  do
  {
    s32 j;
    char piece;
    piece = (idx = bits & 0xF);
    j = i & 0xFF;
    i += 1;
    D_800A167C[j] = (s8) piece;
    D_800A1684[j] = (s8) piece;
    bits >>= 4;
  }
  while (((u32) (i & 0xFF)) < 8U);
}
