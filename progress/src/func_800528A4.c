extern u8 gCurCount;
extern u8 D_800ADFE1;
extern u8 *gCarList;
extern u8 gDecodeBlk[];
extern u8 *gRecords;

/* For a record in state 5, sums each of the four cars' per-lap values (from the car list)
   into the decode block row for this record, starting from the first lap or from the
   record's lap count. Then, if the record's flag 0x4000 is set and the smallest row value is
   at least 21, lowers the row's entry by 10. */
void func_800528A4(void)
{
  u8 *record;
  u8 *base;
  u32 i;
  u8 *table;
  u8 *node;
  u8 *flag;
  u8 *row_addr;
  u32 sum;
  u32 k;
  int row_off;
  u32 *p;
  u32 n;
  u32 min;
  u32 *row;
  u8 *obj2;
  record = gRecords;
  if ((*((u16 *) (record + 0x1E))) != 5)
  {
    return;
  }
  table = gDecodeBlk;
  row_off = 0x118;
  i = 0;
  node = *((u8 **) gCarList);
  flag = &D_800ADFE1;
  base = record;
  for (; i < 4; i += 1)
  {
    if (node == 0)
    {
      continue;
    }
    p = *((u32 **) (*((u8 **) (node + 0x6C))));
    sum = 0;
    p += 1;
    if ((*flag) == 0)
    {
      sum = *p;
    }
    else
    {
      k = 0;
      if (k < (((u32) flag[-1]) - 1))
      do
      {
        k += 1;
        sum += *p++;
      }
      while (k < (u32)(gCurCount - 1));
    }
    n = (*((u16 *) (base + 0x22))) << 4;
    #ifdef PORT
    row_addr = table + n + 0x118;
#else
    row_addr = (u8 *) ((n + (u32) table) + 0x118);
#endif
    #ifdef PORT
    *(u32 *) (row_addr + (i << 2)) = sum;
#else
    *((u32 *) ((i << 2) + (u32) row_addr)) = sum;
#endif
    node = *((u8 **) (node + 4));
  }

  obj2 = gRecords;
  if ((*((u16 *) (obj2 + 0x2C))) & 0x4000)
  {
    row_off = 0x118;
    #ifdef PORT
    row = (u32 *) (table + ((*((u16 *) (obj2 + 0x22))) << 4) + row_off);
#else
    row = (u32 *) ((((*((u16 *) (obj2 + 0x22))) << 4) + (u32) table) + row_off);
#endif
    min = ~0U;
    for (i = 0; i < 4; i += 1)
    {
      if (row[i] < min)
      {
        min = row[i];
      }
    }
    if (min >= 21)
    {
      *((u32 *) ((table + ((*((u16 *) (gRecords + 0x22))) << 4)) + 0x118)) = min - 10;
    }
  }
}
