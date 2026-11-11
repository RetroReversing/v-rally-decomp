/* Raises *maxExtent to the largest coordinate in the part's record table. Records are 7 u16s (type 26,
 * first 3 values) or 9 u16s (type 30, first 4 values); the part's count is at +4 and its table at +0. */
void updateMaxExtent(void *part, u32 *maxExtent)
{
  s32 i;
  s32 j;
  s32 n;
  u16 *p;
  u16 *q;
  u16 *base;
  u16 v;
  char pad[16];
  switch (*((u16 *) (((u8 *) part) + 6)))
  {
    case 26:
      n = *((u16 *) (((u8 *) part) + 4));
      base = *((u16 **) part);
      i = 0;
      if (n > 0)
    {
      do
      {
        j = 0;
        p = base;
        do
        {
          v = base[j];
          if ((*maxExtent) < v)
          {
            *maxExtent = v;
          }
          j++;
        }
        while (j < 3);
        i++;
        base += 7;
      }
      while (i < (*((u16 *) (((u8 *) part) + 4))));
    }
      break;

    case 30:
      n = *((u16 *) (((u8 *) part) + 4));
      base = *((u16 **) part);
      i = 0;
      if (n > 0)
    {
      do
      {
        j = 0;
        p = base;
        do
        {
          v = *p;
          if ((*maxExtent) < v)
          {
            *maxExtent = v;
          }
          j++;
          p++;
        }
        while (j < 4);
        i++;
        base += 9;
      }
      while (i < *((u16 *) (((u8 *) part) + 4)));
    }

  }

}
