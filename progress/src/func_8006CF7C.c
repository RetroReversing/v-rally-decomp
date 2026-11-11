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
  u16 v[1];
} Tbl6C;
extern Slot6C D_800C3650[][4];
extern Code6C gRecordGlyphs[];
extern Tbl6C gSplitRecordIds;
extern s32 D_800ADF30[];
extern void record_put_glyphs(s32,s32,s32,s32);

/* Loads the three record entries of split-screen slot i (ids in gSplitRecordIds, 0xFFFF = empty).
 * Each valid entry draws its name glyphs and stores its initials, flag bits and time value in D_800C3650. */
void func_8006CF7C(u8 i)
{
  Tbl6C *ids = &gSplitRecordIds;
  u8 place = 0;
  u32 id;
  s32 initial;
  Code6C *glyph;

  do
  {
    id = ids->v[i * 3 + place];
    if (id != 0xFFFF)
    {
      glyph = &gRecordGlyphs[id >> 14];
      record_put_glyphs((u8)(place),(u8)(0x17),(u8)(i),(u8)(i));
      D_800C3650[i][place].c6 = ((glyph->a >> 10) & 0x1F) + 0x41;
      D_800C3650[i][place].c7 = ((glyph->a >> 5) & 0x1F) + 0x41;
      initial = (((u8 *) glyph)[1] & 0x1F) + 0x41;
      id &= 0x3FFF;
      D_800C3650[i][place].cC = 1;
      D_800C3650[i][place].c8 = initial;
      if (id & 1)
        id = -id;
      id = D_800ADF30[i] - id;
      D_800C3650[i][place].val = id;
      D_800C3650[i][place].c4 = (glyph->b >> 12) + (glyph->a >> 15) * 16;
    }
    place++;
  }
  while (place < 3);
}
