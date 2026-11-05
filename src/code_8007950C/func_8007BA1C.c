#include "decompdecomp_snapshot_8007ba1c.h"
#line 1 "func.c"
extern s32 D_800A1860;
extern s32 D_800A1864;
extern s32 D_800A1868;
extern s32 D_800A186C;
extern s32 D_800A1870;
extern s32 D_800A1874;
extern f32 D_800A1878;
extern f32 D_800A187C;
extern u8 D_800A73E0[];
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
s32 func_8002DA98(u8 *arg0, s32 *arg1);
void *func_8002E514(void *, void *, void *);
f32 sqrtf(f32);
#define ORG(i) (((s32 *)(D_800AE850 + 0x6E8C))[i])
#define G(i) (((s32 *)(D_800C02AE + 0x5D32))[i])
#define GF(i) (((f32 *)(D_800C02AE + 0x5D32))[i])

u8 func_8007BA1C(u8 *arg0)
{
  s16 a[3];
  s16 b[3];
  s16 c[3];
  s32 m[8];
  f32 dx, dy, dz, len, s;
  f32 ex, ey, ez, len2, dot;
  s32 r;

  func_8002DA98(D_800AE850 + 0x6E78, m);
  b[0] = D_800A1860 - ORG(0);
  b[1] = D_800A1864 - ORG(1);
  b[2] = D_800A1868 - ORG(2);
  func_8002E514(m, b, b);
  c[0] = D_800A186C - ORG(0);
  c[1] = D_800A1870 - ORG(1);
  c[2] = D_800A1874 - ORG(2);
  func_8002E514(m, c, c);
  dx = b[0] - c[0];
  dy = b[1] - c[1];
  dz = b[2] - c[2];
  s = dx * dx;
  s += dy * dy;
  s += dz * dz;
  len = sqrtf(s);
  dx /= len;
  dy /= len;
  dz /= len;
  G(0) = b[0];
  G(1) = b[1];
  G(2) = b[2];
  G(3) = c[0];
  G(4) = c[1];
  G(5) = c[2];
  GF(6) = D_800A1878;
  GF(7) = D_800A187C;
  a[0] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[0] - ORG(0);
  a[1] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[1] - ORG(1);
  a[2] = ((s32 *)(*(u8 **)(arg0 + 0x5C) + 0x54))[2] - ORG(2);
  func_8002E514(m, a, a);
  ex = G(0) - a[0];
  ey = G(1) - a[1];
  r = G(2) - a[2];
  ez = r;
  s = ex * ex;
  s += ey * ey;
  s += ez * ez;
  len2 = sqrtf(s);
  ex /= len2;
  ey /= len2;
  ez /= len2;
  dot = ex * dx;
  dot += ey * dy;
  dot += ez * dz;
  r = 0xFF;
  if (!(GF(6) < dot) && !(GF(7) < dot)) {
    r = D_800A73E0[0x6BE7];
  }
  return r;
}

