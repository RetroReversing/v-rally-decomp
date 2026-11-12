#define F(p,t,o) (*(t *)((u8 *)(p)+(o)))
typedef struct 
{
  u32 words[9];
} Style;void *textObjGet(u32);
extern void group_set_color(Style *, u8, u8, u8, s32);
void draw_palette_sprite(void *, s16, s16, void *);
extern void strCpy(void *, void *);
extern s32 format_to_buffer(void *, void *, ...);
extern void *pool_get_item(s32, s32);
extern u32 gRecordTimeScale;
extern u8 *gSelectState;
extern u8 *gLeague;
extern u8 *gRecords;
extern s32 gSelectStepHandle;
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
void select_draw_results_table(s8 selected)
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
  style = textObjGet(0);
  savedStyle = *style;
  colX = *((u16 *) (((u8 *) style) + 6));
  rowsShown = 0;
  row = 0;
  rowY = (*((u16 *) (((u8 *) style) + 8))) + 14;
  list = gRecords + 68;
  do
  {
    if (list[row * 40] != 91)
    {
      *((u8 *) (((u8 *) style) + 11)) = 255;
      *((u8 *) (((u8 *) style) + 12)) = 255;
      *((u8 *) (((u8 *) style) + 13)) = 255;
      if ((*((s16 *) (((u8 *) gLeague) + 2))) != 3)
      {
        if (((s8) selected) == row)
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }
        if ((*((s16 *) (((u8 *) gLeague) + 2))) == 3)
        {
          goto blinkRow;
        }
      }
      else
      {
        blinkRow:
        if (((*((s8 *) (((u8 *) gSelectState) + 0x229))) == row) && (((*((u16 *) (((u8 *) gLeague) + 4))) % (gRecordTimeScale >> 1)) < (gRecordTimeScale >> 2)))
        {
          *((u8 *) (((u8 *) style) + 11)) = 220;
          *((u8 *) (((u8 *) style) + 12)) = 220;
          *((u8 *) (((u8 *) style) + 13)) = 14;
        }

      }
      group_set_color(style, *((u8 *) (((u8 *) style) + 11)), *((u8 *) (((u8 *) style) + 12)), *((u8 *) (((u8 *) style) + 13)), *((u8 *) (((u8 *) style) + 14)));
      rec = list + (row * 40);
      strCpy(label, rec);
      draw_palette_sprite((void *)(style), (s16)((s16) colX), (s16)((s16) rowY), (void *)(label));
      if ((*((u16 *) (((u8 *) rec) + 12))) == 0)
      {
        value = *((u16 *) (((u8 *) rec) + 14));
        format_to_buffer(label, D_800A5704, value);
        unitStr = D_800A5708;
      }
      else
      {
        format_to_buffer(label, D_800A5704, ((*((u16 *) (((u8 *) rec) + 14))) * 100) / 160);
        unitStr = D_800A570C;
      }
      draw_palette_sprite((void *)(style), (s16)((s16) (-(colX + 88))), (s16)((s16) rowY), (void *)(label));
      draw_palette_sprite((void *)(style), (s16)((s16) (colX + 104)), (s16)((s16) rowY), (void *)(unitStr));
      avg = ((f64) ((((D_800B0D80[row].a + D_800B0D80[row].b) + D_800B0D80[row].c) + D_800B0D80[row].d) + D_800B0D80[row].e)) * D_800A5720;
      tenths = (u16) ((u32) (avg * 10.0f));
      fraction = tenths % 10;
      whole = avg;
      if (fraction)
      {
        format_to_buffer(label, D_800A5710, (u8) whole, fraction);
      }
      else
      {
        format_to_buffer(label, D_800A5718, (u8) whole);
      }
      unitStr = label;
      draw_palette_sprite((void *)(style), (s16)((s16) (-(colX + 194))), (s16)((s16) rowY), (void *)(unitStr));
      rowY += 14;
      rowsShown += 1;
    }
    ++row;
  }
  while (row < 4);
  group_set_color(style, 255, 255, 255, 255);
  while (rowsShown < 4)
  {
    unitStr = pool_get_item(gSelectStepHandle, 341);
    placeholderY = rowY;
    rowsShown += 1;
    draw_palette_sprite((void *)(style), (s16)((s16) colX), (s16)((s16) placeholderY), (void *)(unitStr));
    rowY += 14;
  }

  *style = savedStyle;
}
