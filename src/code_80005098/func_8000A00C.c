#include "common.h"

extern s32 D_800C3594;
extern s32 D_800C35B8;
void func_8000A00C(void)
{
  s32 *a0;
  s32 v;
  s32 off;
  s32 tmp;
  ((void (*)(void)) D_800C3594)();
  a0 = &D_800C35B8;
  v = *a0;
  *a0 = 1 - v;
  off = D_800C35B8 * 4;
  tmp = *((s32 *) ((((u8 *) a0) - (-off)) - 0x10));
  a0 -= 2;
  *((s32 *) (((u8 *) a0) + off)) = tmp;
}
