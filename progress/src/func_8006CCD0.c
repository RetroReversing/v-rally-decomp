typedef struct Slot6C
{
  s32 val;
  u8 c4;
  u8 c5;
  u8 c6;
  u8 c7;
  u8 c8;
  u8 c9[3];
  u8 cC;
  u8 cD[3];
} Slot6C;
typedef struct Code6C
{
  u16 a;
  u16 b;
  u8 pad[10];
} Code6C;
typedef struct Tbl6C
{
  u8 pad[0xE2];
  u16 v[96];
  u16 w[3];
} Tbl6C;
extern Slot6C D_800C3650[][4];
extern Code6C gRecordGlyphs[];
extern Tbl6C gSplitRecordIds;
extern s32 D_800ADF30[];
extern void record_put_glyphs(s32,s32,s32,s32);

/* For each of the three split-record ids, looks up its glyph entry and fills
   the matching display slot in row 16: the three letters, the value and the
   colour nibble. */
void func_8006CCD0(void)
{
  Tbl6C *split = &gSplitRecordIds;
  u8 i = 0;
  u32 id;
  s32 ch;
  Code6C *glyph;

  do
  {
    id = split->w[i];
    if (id != 0xFFFF)
    {
      glyph = &gRecordGlyphs[id >> 14];
      record_put_glyphs((u8)(i),(u8)(0x18),(u8)(0),(u8)(0));
      D_800C3650[16][i].c6 = ((glyph->a >> 10) & 0x1F) + 0x41;
      D_800C3650[16][i].c7 = ((glyph->a >> 5) & 0x1F) + 0x41;
      ch = (((u8 *) glyph)[1] & 0x1F) + 0x41;
      id &= 0x3FFF;
      D_800C3650[16][i].c8 = ch;
      if (id & 1)
        id = -id;
      id = D_800ADF30[16] - id;
      D_800C3650[16][i].val = id;
      D_800C3650[16][i].c4 = (glyph->b >> 12) + (glyph->a >> 15) * 16;
    }
    i++;
  }
  while (i < 3);
}
