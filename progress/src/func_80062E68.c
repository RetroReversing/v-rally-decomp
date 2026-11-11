#define sp18 buf.h
#define sp1A buf.c
typedef struct 
{
  u8 p[6];
  s16 x;
  u16 y;
  u8 pad;
  u8 q;
  u8 r;
  u8 g;
  u8 b;
  u8 a;
} Sp;
typedef struct 
{
  u8 p[0x20];
  u16 a;
  u16 b;
} Sel;
extern u8 *gSlotTableB;
extern Sel *gRecords;
s32 func_80052E94(u16, void *);void *textObjGet(u32);
s32 group_set_color(void *, s32, s32, s32, s32);
void draw_palette_sprite(void *, s16, s16, void *);
s32 memset(void *, s32, s32);
s32 appendString(void *, void *);
s32 formatString(void *, void *, s32, void *);
extern char D_800A5684[];
extern s16 D_800A568C;
extern s8 D_800A568E;
extern char D_800A5690[];
static inline s32 *inline_fn(u8 *arg0, unsigned char arg1, int arg2)
{
  return (s32 *) ((arg0 + ((arg1 * 0x10) + (gRecords->b << arg2))) + 0x2C);
}

/* Draws the three-row label block and then the value column of the record table:
 * each value is shown relative to the first row, with the first row's value shown
 * as is. Rows are 0x16 apart. */
void func_80062E68(void)
{
  struct 
  {
    s16 h;
    s8 c;
    s8 pad[13];
  } buf;
  s32 first = 0;
  s16 *value_x;
  void *value_buf;
  Sp *value_text;
  s32 *row_val;
  Sp *row_text;
  unsigned char row;
  s32 val;
  s32 n;
  row_text = textObjGet(0x10);
  memset(&sp18, 0, 0xF);
  n = 0;
  do
  {
    row = n & 0xFF;
    formatString(&sp18, D_800A5684, row + 1, (((gSlotTableB + (gRecords->a * 0x2C4)) + ((gRecords->b << 6) + 0x2C)) + (row * 0x10)) + 6);
    n++;
    group_set_color(row_text, row_text->q, row_text->r, row_text->g, row_text->b);
    draw_palette_sprite((void *)(row_text), (s16)(row_text->x), (s16)(row_text->y + (row * 0x16)), (void *)(&sp18));
  }
  while (3U > ((u32) (n & 0xFF)));
  row_text = textObjGet(0x12);
  value_text = textObjGet(0x11);
  n = 0;
  value_buf = &buf;
  do
  {
    row = n & 0xFF;
    row_val = inline_fn(gSlotTableB + (177 * (gRecords->a * 4)), row, 6);
    value_x = &value_text->x;
    val = *row_val;
    memset(&sp18, 0, 0xF);
    func_80052E94(val, &sp18);
    draw_palette_sprite((void *)(row_text), (s16)(row_text->x), (s16)(row_text->y + (row * 0x16)), (void *)(&sp18));
    if (row == 0)
    {
      first = val;
    }
    else
    {
      memset(&sp18, 0, 0xF);
      {
        s32 t1 = D_800A568C;
        s32 t2 = D_800A568E;
        sp18 = t1;
        sp1A = t2;
      }
      if (row_text)
      {
        func_80052E94(val - first, &sp1A);
        appendString(value_buf, D_800A5690);
        draw_palette_sprite((void *)(value_text), (s16)(*value_x), (s16)(value_text->y + (((row) - 1) * 0x16)), (void *)(value_buf));
      }
      else
      {
        func_80052E94(val - first, &sp1A);
        appendString(value_buf, D_800A5690);
        draw_palette_sprite((void *)(value_text), (s16)(*value_x), (s16)(value_text->y + ((((unsigned int) row) - 1) * 0x16)), (void *)(value_buf));
      }
    }
    n++;
  }
  while (((u32) (n & 0xFF)) < 3U);
}
