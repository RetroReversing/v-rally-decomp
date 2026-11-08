#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
typedef struct 
{
  u32 words[9];
} Style;void *text_obj_get(u32);
extern void func_80059618(Style *, u8, u8, u8, s32);
void func_800596F4(void *, s16, s16, void *);
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
/* Draws the four-row results table: each row shows a record (name, time or
 * percentage, unit) and its rating, the selected row blinks, and empty rows
 * at the bottom show a placeholder. */
void func_8006874C(s8 selected)
{
  s16 placeholderY;
  Style savedStyle;
  char label[8];
  Style *style;
  u16 colX;
  s16 rowY;
  u8 rowsShown;
  u8 row;
  u8 *rec;
  u8 *unitStr;
  s32 value;
  f32 avg;
  u16 tenths;
  u32 whole;
  u16 fraction;
  u8 *list;
  style = text_obj_get(0);
  savedStyle = *style;
  colX = *((u16 *) (((u8 *) style) + 6));
  rowsShown = 0;
  row = 0;
  rowY = (*((u16 *) (((u8 *) style) + 8))) + 14;
  list = D_800C35A0 + 68;
  do
  {
    if (list[row * 40] != 91)
    {
      *((u8 *) (((u8 *) style) + 11)) = 255;
      *((u8 *) (((u8 *) style) + 12)) = 255;
      *((u8 *) (((u8 *) style) + 13)) = 255;
      if ((*((s16 *) (((u8 *) D_800C3508) + 2))) != 3)
      {
        if (((s8) selected) == row)
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }
        if ((*((s16 *) (((u8 *) D_800C3508) + 2))) == 3)
        {
          goto blinkRow;
        }
      }
      else
      {
        blinkRow:
        if (((*((s8 *) (((u8 *) D_800A1468) + 0x229))) == row) && (((*((u16 *) (((u8 *) D_800C3508) + 4))) % (D_8009D540 >> 1)) < (D_8009D540 >> 2)))
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }

      }
      func_80059618(style, *((u8 *) (((u8 *) style) + 11)), *((u8 *) (((u8 *) style) + 12)), *((u8 *) (((u8 *) style) + 13)), *((u8 *) (((u8 *) style) + 14)));
      rec = list + (row * 40);
      func_80098290(label, rec);
      func_800596F4((void *)(style), (s16)((s16) colX), (s16)((s16) rowY), (void *)(label));
      if ((*((u16 *) (((u8 *) rec) + 12))) == 0)
      {
        value = *((u16 *) (((u8 *) rec) + 14));
        func_80099DF8(label, D_800A5704, value);
        unitStr = D_800A5708;
      }
      else
      {
        func_80099DF8(label, D_800A5704, ((*((u16 *) (((u8 *) rec) + 14))) * 100) / 160);
        unitStr = D_800A570C;
      }
      func_800596F4((void *)(style), (s16)((s16) (-(colX + 88))), (s16)((s16) rowY), (void *)(label));
      func_800596F4((void *)(style), (s16)((s16) (colX + 104)), (s16)((s16) rowY), (void *)(unitStr));
      avg = ((f64) ((((D_800B0D80[row].a + D_800B0D80[row].b) + D_800B0D80[row].c) + D_800B0D80[row].d) + D_800B0D80[row].e)) * D_800A5720;
      tenths = (u16) ((u32) (avg * 10.0f));
      fraction = tenths % 10;
      whole = avg;
      if (fraction)
      {
        func_80099DF8(label, D_800A5710, (u8) whole, fraction);
      }
      else
      {
        func_80099DF8(label, D_800A5718, (u8) whole);
      }
      unitStr = label;
      func_800596F4((void *)(style), (s16)((s16) (-(colX + 194))), (s16)((s16) rowY), (void *)(unitStr));
      rowY += 14;
      rowsShown += 1;
    }
    ++row;
  }
  while (row < 4);
  func_80059618(style, 255, 255, 255, 255);
  while (rowsShown < 4)
  {
    unitStr = func_80057918(D_800C8328, 341);
    placeholderY = rowY;
    rowsShown += 1;
    func_800596F4((void *)(style), (s16)((s16) colX), (s16)((s16) placeholderY), (void *)(unitStr));
    rowY += 14;
  }

  *style = savedStyle;
}
