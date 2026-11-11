extern u8 gStreamState[];
/* Scans slot entries (40 bytes each, name at +0x44) from index start-1 down to 0 and
 * returns the first index whose name starts with an uppercase letter. If none is found,
 * or start is 0, returns start unchanged. */
s8 slot_find_upper_before(s8 start)
{
  u8 found;
  s8 idx;
  u8 *names;

  names = (*((u8 **) (gStreamState + 0x32F2))) + 0x44;
  found = 0;
  if (start != 0)
  {
    idx = start - 1;
    while (1)
    {
      if (((u8) (names[idx * 40] - 0x41)) <= (0x1A - 1))
      {
        found = 1;
        break;
      }
      if (idx == 0)
      {
        break;
      }
      idx--;
    }

    if (found)
    {
      start = idx;
    }
  }
  return start;
}
