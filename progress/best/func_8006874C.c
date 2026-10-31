#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
typedef struct 
{
  u32 words[9];
} Style;
extern Style *func_800592D0(unsigned short);
extern void func_80059618(Style *, u8, u8, u8, s32);
extern void func_800596F4(Style *, s16, s16, void *);
extern void func_80098290(void *, void *);
extern s32 func_80099DF8(void *, void *, ...);
extern void *func_80057918(s32, s32);
extern u32 D_8009D540;
extern u8 *D_800A1468;
extern u8 *D_800C3508;
extern u8 *D_800C35A0;
extern s32 D_800C8328;
extern u8 D_800A5704[];
extern u8 D_800A5708[];
extern u8 D_800A570C[];
extern u8 D_800A5710[];
extern u8 D_800A5718[];
extern f64 D_800A5720;
typedef struct 
{
  u8 a;
  u8 b;
  u8 c;
  u8 d;
  u8 e;
} Rating;
extern Rating D_800B0D80[];
void func_8006874C(s8 selected)
{
  Style saved;
  char text[8];
  Style *style;
  u16 x;
  s16 y;
  u8 shown;
  u8 i;
  u8 *p;
  u8 *unit;
  s32 value;
  f32 average;
  u32 digit;
  u32 whole;
  u16 fraction;
  u8 *list;
  style = func_800592D0(0);
  saved = *style;
  x = *((u16 *) (((u8 *) style) + 6));
  shown = 0;
  i = 0;
  y = (*((u16 *) (((u8 *) style) + 8))) + 14;
  list = D_800C35A0 + 68;
  do
  {
    if (list[i * 40] != 91)
    {
      *((u8 *) (((u8 *) style) + 11)) = 255;
      *((u8 *) (((u8 *) style) + 12)) = 255;
      *((u8 *) (((u8 *) style) + 13)) = 255;
      if ((*((s16 *) (((u8 *) D_800C3508) + 2))) != 3)
      {
        if (((s8) selected) == i)
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }
        if ((*((s16 *) (((u8 *) D_800C3508) + 2))) == 3)
        {
          goto blink;
        }
      }
      else
      {
        blink:
        if (((*((s8 *) (((u8 *) D_800A1468) + 0x229))) == i) && (((*((u16 *) (((u8 *) D_800C3508) + 4))) % (D_8009D540 >> 1)) < (D_8009D540 >> 2)))
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }

      }
      func_80059618(style, *((u8 *) (((u8 *) style) + 11)), *((u8 *) (((u8 *) style) + 12)), *((u8 *) (((u8 *) style) + 13)), *((u8 *) (((u8 *) style) + 14)));
      p = list + (i * 40);
      func_80098290(text, p);
      func_800596F4(style, (s16) x, (s16) y, text);
      if ((*((u16 *) (((u8 *) p) + 12))) == 0)
      {
        value = *((u16 *) (((u8 *) p) + 14));
        func_80099DF8(text, D_800A5704, value);
        unit = D_800A5708;
      }
      else
      {
        value = ((*((u16 *) (((u8 *) p) + 14))) * 100) / 160;
        func_80099DF8(text, D_800A5704, value);
        unit = D_800A570C;
      }
      func_800596F4(style, (s16) (-(x + 88)), (s16) y, text);
      func_800596F4(style, (s16) (x + 104), (s16) y, unit);
      average = ((f64) ((((D_800B0D80[i].a + D_800B0D80[i].b) + D_800B0D80[i].c) + D_800B0D80[i].d) + D_800B0D80[i].e)) * D_800A5720;
      digit = (u16) ((u32) (average * 10.0f));
      fraction = digit % 10;
      whole = average;
      if (fraction)
      {
        func_80099DF8(text, D_800A5710, (u8) whole, fraction);
      }
      else
      {
        func_80099DF8(text, D_800A5718, (u8) whole);
      }
      func_800596F4(style, (s16) (-(x + 194)), (s16) y, text);
      y += 14;
      shown += 1;
    }
    ++i;
  }
  while (i < 4);
  func_80059618(style, 255, 255, 255, 255);
  while (shown < 4)
  {
    void *str;
    str = func_80057918(D_800C8328, 341);
    shown += 1;
    func_800596F4(style, (s16) x, (s16) y, str);
    y += 14;
  }

  *style = saved;
}

