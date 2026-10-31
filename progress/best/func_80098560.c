/* Partial candidate from function #26332 in project #57; rechecked locally. */
s32 func_80098560(u8 *arg0, u8 *s, u32 n)
{
  int new_var3;
  u8 *new_var;
  u8 *d = arg0;
  u8 *new_var2;
  u32 x;
  s32 words;
  if ((((u32) (s - d)) & 3) != 0)
  {
    bytes:
    while ((n--) != 0)
    {
      u8 c = *(s++);
      *(d++) = c;
      if (c == 0)
      {
        goto done;
      }
    }


    goto done;
  }
  x = (u32) d;
  words = n >> 2;
  if (x & 3)
  {
    do
    {
      if ((n--) == 0)
      {
        return (s32) arg0;
      }
      new_var2 = s++;
      {
        u8 c = *new_var2;
        *(d++) = c;
        if (!c)
        {
          goto done;
        }
      }
    }
    while (((u32) d) & 3);
    words = n >> 2;
  }
  while ((--words) != (-1))
  {
    x = *((u32 *) s);
    s += 4;
    if (!(x & 0xff000000))
    {
      goto one;
    }
    if (!(x & 0xff0000))
    {
      goto two;
    }
    if (!(x & 0xff00))
    {
      goto three;
    }
    *((u32 *) d) = x;
    if (!(x & 255))
    {
      goto done;
    }
  }

  n &= 3;
  goto bytes;
  one:
  *d = 0;

  d = d + 4;
  goto done;
  two:
  *((u16 *) d) = x >> (new_var3 = 16);

  goto done;
  three:
  x >>= 16;

  *((u16 *) d) = x;
  d[2] = 0;
  new_var = arg0;
  done:
  return (s32) new_var;

}
