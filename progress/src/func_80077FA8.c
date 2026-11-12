extern u8 *gRecords;
extern u8 gOrderState[];

/* Returns the ascending rank of record arg0 (0 = smallest first word, 3 = largest) within its
 * group of four 32-byte records. The group starts at gOrderState+0x6DAC plus the 16-bit offset
 * stored at gRecords+0x1E. */
u8 func_80077FA8(u8 arg0)
{
  u32 *p;
  u32 *q;
  u8 i;
  u8 n;
  u32 *new_var;
  u32 *tbl;
  u32 t;
  u32 idx;
  int new_var2;

  n = 4;
  idx = arg0 << 5;
#ifdef PORT
  t = *((u16 *) (gRecords + 0x1E));
#else
  t = (u32) gRecords;
  t = *((u16 *) (t + 0x1E));
#endif
  new_var = ((u32 *) (gOrderState + 0x6DAC)) + t;
  tbl = new_var;
  p = (u32 *) (((u8 *) tbl) + idx);
  new_var2 = 1;
  i = 0;
  do
  {
    q = tbl + (i * 8);
    if ((*p) < (*q))
    {
      n--;
    }
    i++;
  }
  while (i < 4);
  return n - new_var2;
}
