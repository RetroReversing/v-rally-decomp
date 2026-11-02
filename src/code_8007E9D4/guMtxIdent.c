#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s32 m[4][4];
} Mtx;
static __inline__ void identF(float mf[4][4])
{
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (i == j) mf[i][j] = 1.0;
      else mf[i][j] = 0.0;
}
static __inline__ void f2l(float mf[4][4], Mtx *m)
{
  int i, j;
  int e1, e2;
  int *ai, *af;
  ai = (int *) &m->m[0][0];
  af = (int *) &m->m[2][0];
  for (i = 0; i < 4; i++)
    for (j = 0; j < 2; j++)
    {
      e1 = (long) (mf[i][j * 2] * (float) 0x00010000);
      e2 = (long) (mf[i][j * 2 + 1] * (float) 0x00010000);
      *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff);
      *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
    }
}
void guMtxIdent(Mtx *m)
{
  float mf[4][4];
  identF(mf);
  f2l(mf, m);
}
