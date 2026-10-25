#include "common.h"

extern s32 D_800C81D4;
extern u8 D_800C35C8;
extern u8 D_800C35C9;
extern u8 D_800C35CA;
extern u8 D_800C35CB;
extern u8 D_800C35CC;
extern u8 D_800C35CD;
extern u8 D_800C35CE;
extern u8 D_800C35CF;
s32 func_80086AD8(void *, s32);
s32 func_80089980(void);
void func_80038DF8(void)
{
  u8 s0;
  int new_var;
  for (s0 = 0; s0 < 0x27; s0++)
  {
    new_var = s0 * 12;
    func_80086AD8((void *) (D_800C81D4 + new_var), 0);
  }

  D_800C35C8 = 0xFF;
  D_800C35C9 = 0;
  D_800C35CA = 0xFF;
  D_800C35CB = 0xFF;
  D_800C35CC = 0xFF;
  D_800C35CD = 0xFF;
  D_800C35CE = 0xFF;
  D_800C35CF = 0xFF;
  func_80089980();
}
