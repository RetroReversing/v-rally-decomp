s32 str_compare_fold();

/* Binary search over the table of s32 keys at +0x80 (count at +0x7C, entries 1..count).
 * str_compare_fold compares the search key with an entry; a return of 2 means a match.
 * Returns the matching entry's value, or 0 if none is found. */
s32 order_table_search(void *table, s32 key)
{
  s32 mid;
  s32 cmp;
  s32 hi;
  s32 lo;
  void *entry;

  hi = *((s32 *) (((char *) table) + 0x7C));
  lo = 1;
  do
  {
    mid = (lo + hi) / 2;
    entry = (void *)((mid << 2) + (s32)table);
    if (str_compare_fold(key, *((s32 *) (((char *) entry) + 0x80))) == 2)
    {
      return *((s32 *) (((char *) entry) + 0x80));
    }
    cmp = str_compare_fold(key, *((s32 *) (((char *) entry) + 0x80)));
    if (cmp == 1)
    {
      if ((hi - lo) == cmp)
      {
        entry = table;
        if (str_compare_fold(key, *((s32 *) (((char *) ((hi * 4) + entry)) + 0x80))) == 2)
        {
          return *((s32 *) (((char *) ((hi * 4) + entry)) + 0x80));
        }
      }
      else
      {
        lo = mid;
      }
    }
    else
    {
      hi = mid;
    }
  }
  while (lo != hi);
  return 0;
}
