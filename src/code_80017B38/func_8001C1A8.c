#include "common.h"

void *guMtxCatF(f32 *, f32 *, f32 *);
void guRotateF(f32 *, s32, f32, f32, f32);
void func_8001C1A8(s32 *arg0, f32 *arg1)
{
  f32 sp18[16];
  f32 sp58[16];
  f32 sp98[16];
  f32 spD8[16];
  f32 *a2;
  f32 *v1;
  f32 *a0;
  f32 *s2;
  s32 i;
  s32 j;
  guRotateF(sp18, arg0[0], 1.0f, 0.0f, 0.0f);
  guRotateF(sp58, arg0[1], 0.0f, 1.0f, 0.0f);
  guRotateF(sp98, arg0[2], 0.0f, 0.0f, 1.0f);
  guMtxCatF(sp98, sp18, spD8);
  guMtxCatF(spD8, sp58, spD8);
  s2 = arg1;
  i = 0;
  a2 = sp18;
  do
  {
    j = 0;
 do { } while (0);
    a0 = s2;
    v1 = a2 + 48;
    do
    {
      *a0 = *v1;
      v1++;
      j++;
      a0++;
    }
    while (j < 3);
    a2 += 4;
    i++;
    s2 += 4;
  }
  while (i < 3);
}
