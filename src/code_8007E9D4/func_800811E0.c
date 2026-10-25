#include "common.h"

s32 func_8008ACA0();
s32 func_8008ACD0();
s32 func_8008DFC0();
void func_80081130();
extern char D_800A7780[];
extern char D_800A9930[];
extern char D_800C7938[];
extern char D_800C6E90[];
extern s32 D_800B730C;
extern s32 D_800B7310;

void func_800811E0(void)
{
  char *s0;

  func_8008ACA0(D_800C7938, D_800C6E90, 1);
  s0 = D_800A7780;
  func_8008ACD0(s0, 0xA, func_80081130, 0, D_800A9930, 0x7F);
  func_8008DFC0(s0);
  D_800B730C = 0;
  D_800B7310 = 0;
}
