extern u8 gOrderState[];
extern u8 gStreamState[];
extern u8 *gRecords;
extern u8 *gSelectState;
extern u16 D_800A1504[];
extern u16 D_800A150C[];
extern u16 D_800A1514[];
extern u16 D_800A1520[];
extern u16 D_800A1528;
extern u16 D_800A152A;
extern u16 D_800A152C;
extern s32 D_800A1538[];
extern u8 aTexPackDir[];
extern void func_8004D31C(void);
extern s32 select_stream_char(u8, u8, u8);void *textObjGet(u32);
extern void func_80047CC0(s32);
extern u8 *find_object_by_id(s32);
extern void func_80047C2C(s32, s32);
extern void resolve_path(void *);
extern void func_8004C7F0(void *);
static inline u8 tableByte(int off)
{
  return gOrderState[off];
}

/* Refreshes the HUD: the position colour (from the record's first-colour
 * bytes), the tier colours picked from the byte at gRecords[0x2E], and the
 * distance-band colour at 118 and 132. Also resets the HUD flag at gSelectState. */
void func_8005CE80(void)
{
  s32 color;
  u8 *slot;
  {
    u8 *rec;
    func_8004D31C();
    rec = gRecords;
    color = select_stream_char(rec[0x1F], rec[0x21], rec[0x23]);
  }
  slot = textObjGet(4);
  *((u16 *) (slot + 4)) = D_800A1504[color & 0xFF];
  slot = textObjGet(0xA);
  *((u16 *) (slot + 4)) = D_800A150C[tableByte((gRecords[0x2E] * 0x1C) + 0x1300)];
  slot = textObjGet(6);
  *((u16 *) (slot + 4)) = D_800A1514[tableByte((gRecords[0x2E] * 0x1C) + 0x1301)];
  slot = textObjGet(8);
  *((u16 *) (slot + 4)) = D_800A1520[tableByte((gRecords[0x2E] * 0x1C) + 0x1302)];
  slot = textObjGet(0xC);
  if ((*((f32 *) ((gOrderState + (gRecords[0x2E] * 0x1C)) + 0x1304))) <= 118.0f)
  {
    *((u16 *) (slot + 4)) = D_800A1528;
  }
  else
    if ((*((f32 *) ((gOrderState + (gRecords[0x2E] * 0x1C)) + 0x1304))) <= 132.0f)
  {
    *((u16 *) (slot + 4)) = D_800A152A;
  }
  else
  {
    *((u16 *) (slot + 4)) = D_800A152C;
  }
  func_80047CC0(D_800A1538[color & 0xFF]);
  func_80047C2C(*((s32 *) (find_object_by_id(0) + 0x178)), 0);
  resolve_path(aTexPackDir);
  func_8004C7F0((gOrderState + (gRecords[0x2E] * 0x1C)) + 0x130C);
  slot = textObjGet(0x10);
  *((f32 *) (gStreamState + 0x6A4A)) = *((f32 *) (slot + 0x10));
  gSelectState[0x2BD] = 1;
}
