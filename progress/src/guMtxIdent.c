typedef struct 
{
  s32 m[4][4];
} Mtx;
/* Sets mf to the 4x4 identity matrix. */
static __inline__ void identF(float mf[4][4])
{
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (i == j) mf[i][j] = 1.0;
      else mf[i][j] = 0.0;
}
/* Packs the float matrix mf into the fixed-point Mtx m, 16.16 integer and fraction halves. */
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
/* Sets the fixed-point matrix m to the identity. */
void guMtxIdent(Mtx *m)
{
  float mf[4][4];
  identF(mf);
  f2l(mf, m);
}
