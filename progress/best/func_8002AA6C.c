extern char D_8009CEE0[];
extern u8 D_8009CEE8;
static inline static int inline_fn(s32 arg0)
{
  return arg0 + 1;
}

s32 func_8002AA6C(char *src, char *end)
{
  unsigned long new_var;
  char *look;
  char *lim;
  char buf[0x21];
  char *out;
  char *p;
  char *q;
  s32 c;
  s32 c0;
  s32 n;
  look = src + 1;
  out = buf;
  lim = buf + 0x11;
  for (;;)
  {
    c = *src;
    if ((c == 0x20) || (c == 9))
    {
      *out = 0;
      goto done;
    }
    if ((c == 0x2C) || (c == 0xD))
    {
      *out = 0;
      goto done;
    }
    if (c == 0x23)
    {
      *out = 0;
      goto done;
    }
    if (c == 0x2F)
    {
      if ((look < end) && ((*look) == c))
      {
        *out = 0;
        goto done;
      }
    }
    if (src >= end)
    {
      *out = 0;
      goto done;
    }
    look++;
    *out = *src;
    out++;
    src++;
    if (((s32) out) < ((s32) lim))
    {
      continue;
    }
    goto done;
  }

  done:
  if (D_8009CEE8 != 0xFF)
  {
    c0 = buf[0];
    c0 = 0;
    n = 0;
    do
    {
      p = buf;
      q = *((char **) (D_8009CEE0 + c0));
      ;
      if (c0 == (*q))
      {
        if (c0 != 0)
        {
          while ((*p) != 0)
          {
            q++;
            p++;
            if ((n = *q) != (*p))
            {
              break;
            }
            end = p;
            if ((*end) == 0)
            {
              break;
            }
          }

        }
      }
      new_var = inline_fn(n);
      ;
      if ((*end) == 0)
      {
        if ((*q) == 0)
        {
          return new_var;
        }
      }
      c0 += 0xC;
      n++;
    }
    while ((*(((u8 *) (&D_8009CEE8)) + c0)) != 0xFF);
  }

  return 0;
}

