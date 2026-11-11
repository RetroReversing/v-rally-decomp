typedef struct
{
  u16 flag : 1;
  u16 letter1 : 5;
  u16 letter2 : 5;
  u16 letter3 : 5;
  u16 track : 4;
  u16 values : 12;
  u16 flag2 : 1;
  u16 code : 7;
  u16 zero : 8;
  u8 b6;
  u8 b7;
  u16 time;
  u16 x;
  u16 y;
} RecordGlyph;
typedef struct {
  u8 name[3];
  u8 pad47;
  u8 car;
  u8 pad49[4];
  u8 flags_d;
  u8 pad4e;
  u8 flags_f;
  u8 pad50[2];
  u16 time;
  u8 a[4];
  u8 b[4];
  u8 d[4];
  s16 v[4];
  s32 xy;
} RecordEntry;
typedef struct { u8 pad[0x44]; RecordEntry e[4]; } RecordTable;
extern RecordTable *gRecords;
extern RecordGlyph gRecordGlyphs[];
extern u8 D_800A16F4[];

/* Packs the saved record for one slot into its glyph entry: time, position,
 * name letters, car and tier, then the per-lap digits. */
void func_8006F0E0(u8 slot)
{
  s32 index = slot;
  RecordGlyph *glyph;
  RecordEntry *r;
  u16 time;
  u8 i;
  u32 j;
  s32 k;
  s32 value;

  time = gRecords->e[index].time;
  glyph = &gRecordGlyphs[index];
  if (time > 65530U)
  {
    time = 65530;
  }
  glyph->time = time;
  glyph->x = gRecords->e[index].xy;
  glyph->y = *(u16 *)&gRecords->e[index].xy;
  if (D_800A16F4[index] >= 4U)
  {
    D_800A16F4[index] = 3;
  }
  r = &((RecordTable *)((u8 *)gRecords + index * 40))->e[0];
  k = D_800A16F4[index] << 5;
  glyph->code = (u8)k + r->car;
  glyph->flag2 = r->flags_d;
  glyph->letter1 = r->name[0] - 0x41;
  glyph->letter2 = r->name[1] - 0x41;
  glyph->letter3 = r->name[2] - 0x41;
  k = r->flags_f;
  glyph->zero = 0;
  glyph->b6 = 0;
  glyph->b7 = 0;
  glyph->track = k & 15;
  glyph->flag = (k & 16) >> 4;
  glyph->values = 0;
  i = 0;
  do
  {
    j = i;
    k = gRecords->e[index].a[j];
    if (k < 3U)
    {
      glyph->zero += (k & 3) << (j * 2);
    }
    value = (gRecords->e[index].v[j] + 20) / 10;
    if ((u16)value < 6U)
    {
      k = (value & 7) << (3 * j);
      glyph->values += (u16)k;
    }
    k = gRecords->e[index].b[j];
    if (k < 3U)
    {
      glyph->b6 += (k & 3) << (j * 2);
    }
    k = gRecords->e[index].d[j];
    if (k < 3U)
    {
      glyph->b7 += (k & 3) << (j * 2);
    }
    i++;
  }
  while (i < 4U);
}
