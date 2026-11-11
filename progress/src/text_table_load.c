typedef struct E { u8 *text; u16 count; u8 pad[14]; u16 n; s32 *vals; } E;
typedef struct R { u8 a[14]; u16 n; s32 v; } R;
extern u16 D_800ADFD0; extern u8 D_800A5028; extern s32 gSnapIndex; extern E *g_rec_val; extern s32 *D_800B0BCC,*D_800AFA60;
extern E *func_800523EC(void); extern void formatString(u8*,u8*,u8*); extern s32 getTexturePack(u8*,s32); extern s32 func_8001B730(u8*); extern s32 *poolAlloc(s32,s32);
extern void func_80052194(u16),func_80052224(u16),func_800522B0(u16),func_8005235C(u16),func_80052108(u16);

/* Loads the text table for the current block: each 20-byte record's text is
 * parsed into its value (a leading '0' marks an entry whose count is
 * reduced by one), then an index table 0..count-1 is built. Finally, when the
 * mode is in range and the flag is set, the matching setup routine runs. */
E *text_table_load(void)
{
  E *tbl;
  u8 *line;
  R *rec;
  s32 i, stride;
  u8 num[16];
  stride = D_800ADFD0 * 13;
  tbl = func_800523EC();
  line = tbl->text;
  rec = (R *)line;
  for (i = 0; i < tbl->count; rec++, i++, line += 0x14)
  {
    if ((*line == '0') & (*line < ':'))
    {
      formatString(num, &D_800A5028, line + 2);
      rec->n--;
    }
    else
      formatString(num, &D_800A5028, line);
    rec->v = getTexturePack(num, stride);
    func_8001B730(line);
  }
  D_800B0BCC = (s32 *)tbl->text;
  D_800AFA60 = poolAlloc(1, tbl->count * 2);
  for (i = 0; i < tbl->count; i++)
    ((u16 *)D_800AFA60)[i] = i;
  if (g_rec_val->n == 1 && (u32)gSnapIndex < 8U)
  {
    switch (gSnapIndex)
    {
    case 0: func_80052194(tbl->count); break;
    case 1: func_80052224(tbl->count); break;
    case 2: func_800522B0(tbl->count); break;
    case 3: func_8005235C(tbl->count); break;
    case 4: func_80052108(tbl->count); break;
    case 5:
    case 6:
    case 7: break;
    }
  }
  return tbl;
}
