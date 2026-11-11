extern u8 gOrderState[];
extern u8 gStreamState[];
extern s32 gCategoryScores[];
extern s32 compareScores();
void shell_sort(void *, s32, s32, void *);
static inline u16 inline_fn(u8 *arg0)
{
  return *((u16 *) (arg0 + 0x22));
}

/* Totals the four score categories over the entries of the current record
 * list, then ranks the categories by total with a shell sort. Returns the
 * category at the given rank (0 = best). */
u8 getRankedIndex(s32 rank)
{
  u8 order[4];
  u8 i;
  u8 j;
  u16 count;
  s32 sum;
  u8 *base;
  u8 *tbl;
  s32 *res;
  s32 sel = rank;
  i = 0;
  base = *((u8 **) (gStreamState + 0x32F2));
  tbl = gOrderState + 0x7EC8;
  res = gCategoryScores;
  for (; i < 4; i++)
  {
    count = inline_fn(base);
    sum = 0;
    for (j = 0; j < count; j++)
    {
      sum += *((s32 *) ((tbl + (j * 16)) + (i * 4)));
    }

    res[i] = sum;
  }

  for (i = 0; i < 4; i++)
  {
    order[i] = i;
  }

  shell_sort(order, 4, 1, compareScores);
  return order[sel & 0xFF];
}
