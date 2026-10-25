#include "common.h"

extern u8 D_800AE850[];
extern s32 D_800ADF98;
void func_80009E7C(void)
{
  s32 *a0;
  s32 v;
  s32 off;
  s32 tmp;
  ((void (*)(void)) (*((s32 *) (D_800AE850 + 0x11F4))))();
  a0 = &D_800ADF98;
  v = *a0;
  *a0 = 1 - v;
  off = D_800ADF98 * 4;
  tmp = *((s32 *) ((((u8 *) a0) - (-off)) - 0x10));
  a0 -= 2;
  *((s32 *) (((u8 *) a0) + off)) = tmp;
}
