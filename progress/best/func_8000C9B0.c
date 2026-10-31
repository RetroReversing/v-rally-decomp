typedef struct 
{
  s16 code;
  s16 pad2;
  u8 w4;
  u8 pad5;
  s8 k6;
  s8 pad7;
  s8 k8;
  u8 pad9[7];
} Glyph;
typedef struct 
{
  u8 pad0[0x8];
  u8 adv;
  u8 pad9[0xF];
  Glyph *glyphs;
} Font;
extern s32 func_8008E118(u8 *);
extern void func_8008E3A0(char *, s32);
extern char D_800A3F28[];
s32 func_8000C9B0(Font **arg0, u8 *arg1, u8 arg2, f32 arg3, u8 arg4)
{
  unsigned long new_var;
  s32 s0;
  s32 s2;
  s32 s3;
  s8 s4;
  s32 s5;
  s32 t0;
  u8 idx;
  s32 v;
  u8 *a0;
  u8 *a1;
  Font *s1;
  Glyph *g;
  f32 fv0;
  f32 fv1;
  s5 = 0;
  s2 = 0;
  if (arg4 == 0)
  {
    s4 = 1;
  }
  else
    if (arg4 == 1)
  {
    s4 = 2;
  }
  else
  {
    s4 = 1;
  }
  s1 = arg0[s2 & 0xFF];
  s0 = 0;
  s3 = func_8008E118(arg1);
  if ((s3 == 0) | (s3 >= 0xA1))
  {
    func_8008E3A0(D_800A3F28, s3);
  }
  if (s0 < s3)
  {
    a0 = arg1;
    a1 = arg1 + s3;
    do
    {
      idx = (*a0) - 0x20;
      new_var = -0x80;
      t0 = 0;
      if (((u8) idx) != 0)
      {
        idx = (u8) idx;
        if ((((u8) arg2) != 0) & (s1->glyphs[idx].code == new_var))
        {
          t0 = 0;
          do
          {
            v = s2 + 1;
            s2 = v & (-((v & 0xFF) != ((u8) arg2)));
            s1 = arg0[s2 & 0xFF];
            t0++;
          }
          while ((s1->glyphs[idx].code == (-0x80)) & ((t0 & 0xFF) != ((u8) arg2)));
        }
        g = &s1->glyphs[idx];
        if (g->code != (-0x80))
        {
          fv1 = ((f32) g->w4) * arg3;
          s0 = (s0 - s4) + (g->k6 + s5);
          fv0 = (f32) s0;
          s5 = g->k8;
 do { fv0 = fv0 + fv1; do { s0 = (s32) fv0; } while (0); } while (0);
        }
      }
      else
      {
        fv1 = ((f32) s1->glyphs[0].w4) * arg3;
        fv0 = ((f32) s0) + fv1;
        s0 = (s32) fv0;
      }
      a0++;
      s0 += s1->adv;
    }
    while (a0 < a1);
  }
  return (s0 - s1->adv) + s5;
}
