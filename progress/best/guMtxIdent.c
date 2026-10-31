typedef struct 
{
  s32 m[4][4];
} Mtx;
void guMtxIdent(Mtx *m)
{
  f32 mf[4][4];
  f32 *new_var;
  s32 i;
  s32 j;
  s32 e1;
  s32 e2;
  s32 *ai;
  s32 *af;
  for (i = 0; i < 4; i++)
  {
    for (j = 0; j < 4; j++)
    {
      if (i == j)
      {
        mf[i][j] = 1.0f;
      }
      else
        if (mf)
      {
        mf[i][j] = 0.0f;
      }
      else
      {
        mf[i][j] = 0.0f;
      }
    }

  }

  ai = &m->m[0][0];
  af = &m->m[2][0];
  for (i = 0; i < 4; i++)
  {
 do { for (j = 0; j < 2; j++) { new_var = mf[i]; e1 = (s32) (new_var[j * 2] * ((f32) 0x00010000)); e2 = (s32) (new_var[(j * 2) + 1] * ((f32) 0x00010000)); *(ai++) = (e1 & 0xffff0000) | ((e2 >> 16) & 0xffff); *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff); } } while (0);
  }

}
