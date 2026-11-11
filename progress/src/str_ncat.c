s32 str_len(u8 *);

/* Appends at most `max` bytes of `src` to the end of `dst`, always NUL-terminating. Returns `dst`. */
u8 *str_ncat(u8 *dst, u8 *src, s32 max)
{
  u8 *out;
  u8 *in;
  s32 n;
  u8 c;
  u8 d;
  in = src;
  n = max;
  if (n == 0)
  {
    return dst;
  }
  out = dst + str_len(dst);
  c = (*(out++) = *(in++));
  if (c != 0)
  {
    while (c != 0)
    {
      n--;
      if (n == 0)
      {
        *out = 0;
        break;
      }
      d = *(in++);
      *(out++) = d;
      c = d;
    }

  }
  return dst;
}
