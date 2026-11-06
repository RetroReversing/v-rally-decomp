typedef struct 
{
  s16 code;
  s16 pad2;
  u8 w;
  u8 pad5;
  s8 pre;
  s8 pad7;
  s8 post;
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
s32 func_8000C9B0(void *fonts, void *str, u8 nfonts, f32 scale, u8 mode)
{
  s32 kern = 0;
  u8 fi = 0;
  s32 x;
  s32 len;
  u8 sp;
  Font *f;
  s32 i;
  u8 c;
  u8 n;
  Glyph *g;
  if (mode == 0)
  {
    sp = 1;
  }
  else
    if (mode == 1)
  {
    sp = 2;
  }
  else
  {
    sp = 1;
  }
  f = ((Font **)fonts)[fi];
  x = 0;
  len = func_8008E118(str);
  if ((len == 0) | (len > 0xA0))
  {
    func_8008E3A0(D_800A3F28, len);
    __builtin_mips_debug_break();
  }
  for (i = 0; i < len; i++)
  {
    c = ((u8 *)str)[i];
    c -= 0x20;
    n = 0;
    if (c)
    {
      while ((f->glyphs[c].code == (-0x80)) & (n != nfonts))
      {
        fi++;
        if (fi == nfonts)
        {
          fi = 0;
        }
        f = ((Font **)fonts)[fi];
        n++;
      }

      if (f->glyphs[c].code != (-0x80))
      {
        x += (f->glyphs[c].pre + kern) - sp;
        kern = f->glyphs[c].post;
        x = ((f32) x) + (f->glyphs[c].w * scale);
      }
    }
    else
    {
      s32 t;
      t = ((f32) x) + (f->glyphs[0].w * scale);
      x = t;
    }
    x += f->adv;
  }

  return (x - f->adv) + kern;
}

