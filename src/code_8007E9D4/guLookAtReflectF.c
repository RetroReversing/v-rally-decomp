#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct { u8 col[3]; s8 pad1; u8 colc[3]; s8 pad2; s8 dir[3]; s8 pad3; s32 pad4; } LightT;
typedef struct { LightT l[2]; } LookAtT;
void guMtxIdentF(f32 mf[4][4]);
f32 sqrtf(f32);

void guLookAtReflectF(f32 mf[4][4], LookAtT *l, f32 xEye, f32 yEye, f32 zEye,
                      f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp)
{
  f32 len, xLook, yLook, zLook, xRight, yRight, zRight;

  guMtxIdentF(mf);

  xLook = xAt - xEye;
  yLook = yAt - yEye;
  zLook = zAt - zEye;
  len = -1.0 / sqrtf(xLook * xLook + yLook * yLook + zLook * zLook);
  xLook *= len;
  yLook *= len;
  zLook *= len;

  xRight = yUp * zLook - zUp * yLook;
  yRight = zUp * xLook - xUp * zLook;
  zRight = xUp * yLook - yUp * xLook;
  len = 1.0 / sqrtf(xRight * xRight + yRight * yRight + zRight * zRight);
  xRight *= len;
  yRight *= len;
  zRight *= len;

  xUp = yLook * zRight - zLook * yRight;
  yUp = zLook * xRight - xLook * zRight;
  zUp = xLook * yRight - yLook * xRight;
  len = 1.0 / sqrtf(xUp * xUp + yUp * yUp + zUp * zUp);
  xUp *= len;
  yUp *= len;
  zUp *= len;

  l->l[0].dir[0] = (xRight * 128.0f < 127.0f) ? (s32)(xRight * 128.0f) : 127;
  l->l[0].dir[1] = (yRight * 128.0f < 127.0f) ? (s32)(yRight * 128.0f) : 127;
  l->l[0].dir[2] = (zRight * 128.0f < 127.0f) ? (s32)(zRight * 128.0f) : 127;
  l->l[1].dir[0] = (xUp * 128.0f < 127.0f) ? (s32)(xUp * 128.0f) : 127;
  l->l[1].dir[1] = (yUp * 128.0f < 127.0f) ? (s32)(yUp * 128.0f) : 127;
  l->l[1].dir[2] = (zUp * 128.0f < 127.0f) ? (s32)(zUp * 128.0f) : 127;

  l->l[0].col[0] = 0;
  l->l[0].col[1] = 0;
  l->l[0].col[2] = 0;
  l->l[0].pad1 = 0;
  l->l[0].colc[0] = 0;
  l->l[0].colc[1] = 0;
  l->l[0].colc[2] = 0;
  l->l[0].pad2 = 0;
  l->l[1].col[0] = 0;
  l->l[1].col[1] = 0x80;
  l->l[1].col[2] = 0;
  l->l[1].pad1 = 0;
  l->l[1].colc[0] = 0;
  l->l[1].colc[1] = 0x80;
  l->l[1].colc[2] = 0;
  l->l[1].pad2 = 0;

  mf[0][0] = xRight;
  mf[1][0] = yRight;
  mf[2][0] = zRight;
  mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

  mf[0][1] = xUp;
  mf[1][1] = yUp;
  mf[2][1] = zUp;
  mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);

  mf[0][2] = xLook;
  mf[1][2] = yLook;
  mf[2][2] = zLook;
  mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

  mf[0][3] = 0;
  mf[1][3] = 0;
  mf[2][3] = 0;
  mf[3][3] = 1;
}
