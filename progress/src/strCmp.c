/* Compare two NUL-terminated strings, like the libc strcmp. Returns the
 * difference of the first differing bytes, or 0 if they are equal. Compares
 * byte by byte until the first string is word-aligned, then word by word. */
s32 strCmp(const u8 *str1, const u8 *str2)
{
  s32 diff;
  u32 word0;
  u32 word1;
#ifdef PORT
  if ((((uintptr_t) str1) - ((uintptr_t) str2)) & 3)
#else
  if ((((u32) str1) - ((u32) str2)) & 3)
#endif
  {
    do
    {
      u32 d = *str2;
      u32 c = *str1;
      str1++;
      str2++;
      diff = (word0 = c) - d;
      if ((diff != 0) || (c == 0))
      {
        return diff;
      }
    }
    while (1);
  }
#ifdef PORT
  while (((uintptr_t) str1) & 3)
#else
  while (((u32) str1) & 3)
#endif
  {
    u32 d = *str2;
    u32 c = *str1;
    str1++;
    str2++;
    diff = (word0 = c) - d;
    if ((diff != 0) || (word0 == 0))
    {
      return diff;
    }
  }

  for (;;)
  {
    word0 = *((const u32 *) str1);
    word1 = *((const u32 *) str2);
    str1 += 4;
    str2 += 4;
    diff = word0 - word1;
    if (diff != 0)
    {
      if (!(word0 & 0xFF000000))
      {
        diff = 0xFF000000;
      }
      else
        if (!(word0 & 0xFF0000))
      {
        diff = 0xFFFF0000;
      }
      else
        if (!(word0 & 0xFF00))
      {
        diff = 0xFFFFFF00;
      }
      else
      {
        return diff;
      }
      return (word0 & diff) - (word1 & diff);
    }
    if (((((word0 << 24) == 0) || (!(word0 & 0xFF00))) || (!(word0 & 0xFF0000))) || (!(word0 & 0xFF000000)))
    {
      return diff;
    }
  }

}
