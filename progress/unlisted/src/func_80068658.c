extern u8 gStreamState[];

/* Returns the first slot after `start` (up to slot 3) whose 0x28-byte entry starts with an
   uppercase letter 'A'..'Z'; if none is found, returns `start` unchanged. */
s8 func_80068658(s8 start)
{
  s8 result;
  u8 found;
  u8 *entries;

  entries = (*((u8 **) (gStreamState + 0x32F2))) + 0x44;
  result = start;
  found = 0;
  if (start < 3)
  {
    start += 1;
    while (1)
    {
      if (((u32) (entries[start * 0x28] - 0x41)) < 0x1A)
      {
        found = 1;
        break;
      }
      if (start >= 3)
      {
        break;
      }
      start++;
    }

    if (found)
    {
      result = start;
    }
  }
  return result;
}
