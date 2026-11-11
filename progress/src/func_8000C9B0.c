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

extern s32 str_len(u8 *);
extern void func_8008E3A0(char *, s32);
extern char D_800A3F28[];

/* Returns the pixel width of a string drawn with a list of fonts. A character missing from
 * the current font (code == -0x80) is looked up in the next font in the list. mode 1 uses
 * wider letter spacing (2) than the other modes (1). */
s32 func_8000C9B0(void *font_list, void *text, u8 font_count, f32 scale, u8 mode)
{
  s32 kerning = 0;
  u8 font_idx = 0;
  s32 pen_x;
  s32 text_len;
  u8 spacing;
  Font *font;
  s32 i;
  u8 ch;
  u8 tried;
  Glyph *g;

  if (mode == 0)
  {
    spacing = 1;
  }
  else
    if (mode == 1)
  {
    spacing = 2;
  }
  else
  {
    spacing = 1;
  }
  font = ((Font **)font_list)[font_idx];
  pen_x = 0;
  text_len = str_len(text);
  if ((text_len == 0) | (text_len > 0xA0))
  {
    func_8008E3A0(D_800A3F28, text_len);
    __builtin_mips_debug_break();
  }
  for (i = 0; i < text_len; i++)
  {
    ch = ((u8 *)text)[i];
    ch -= 0x20;
    tried = 0;
    if (ch)
    {
      while ((font->glyphs[ch].code == (-0x80)) & (tried != font_count))
      {
        font_idx++;
        if (font_idx == font_count)
        {
          font_idx = 0;
        }
        font = ((Font **)font_list)[font_idx];
        tried++;
      }

      if (font->glyphs[ch].code != (-0x80))
      {
        pen_x += (font->glyphs[ch].pre + kerning) - spacing;
        kerning = font->glyphs[ch].post;
        pen_x = ((f32) pen_x) + (font->glyphs[ch].w * scale);
      }
    }
    else
    {
      s32 t;
      t = ((f32) pen_x) + (font->glyphs[0].w * scale);
      pen_x = t;
    }
    pen_x += font->adv;
  }

  return (pen_x - font->adv) + kerning;
}
