typedef struct
{
  char *name;
  s32 val;
  u8 id;
  u8 pad[3];
} NameEnt;
extern NameEnt D_8009CEE0[];
extern u8 D_8009CEE8;

/* Copies the next token from src (up to a space, tab, comma, CR, '#', or a "//" comment)
   into a 16-char buffer, then looks it up in the name table D_8009CEE0 (ended by id 0xFF).
   Returns the table index + 1 on a match, or 0 if the token is not in the table. */
s32 func_8002AA6C(char *src, char *end)
{
  char *look;
  char *lim;
  char buf[0x11];
  char *p;
  char *q;
  s32 c;
  s32 i;
  char *out;
  s32 hash = 0x23;
  s32 slash = 0x2F;
  out = buf;
  lim = buf + 0x11;
  look = src + 1;
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
    if (c == hash)
    {
      *out = 0;
      goto done;
    }
    if (c == slash)
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
  i = 0;
  if (D_8009CEE0[0].id != 0xFF)
  {
    do
    {
      p = buf;
      q = D_8009CEE0[i].name;
      while ((((*p) == (*q)) && ((*p) != 0)) && ((*q) != 0))
      {
        p++;
        q++;
      }

      {
        s32 r = 1;
        if (*p == 0) r = *q != 0;
        if (r) goto next;
      }
      {
        return i + 1;
      }
      next:
      i++;
    }
    while (D_8009CEE0[i].id != 0xFF);
  }
  return 0;
}
