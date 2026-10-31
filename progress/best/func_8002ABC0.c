extern void func_8008E13C(void *, void *, s32);
extern u8 D_8009CEE9[];
extern u8 D_8009E260;
extern void (*D_8009CEE4[])(void *);
typedef struct 
{
  s8 text[68];
  s32 number;
  u8 numeric;
  u8 pad[3];
} Token;
s32 func_8002ABC0(s32 cmd, s8 *p, s8 *end)
{
  u8 work[1976];
  s8 buf[72];
  s16 n;
  s16 len;
  u8 neg;
  u8 hex;
  s16 quoted;
  u32 i;
  register s32 command = cmd - 1;
  while (((((((*p) != 32) & ((*p) != 9)) && (((*p) != 44) & ((*p) != 13))) && ((*p) != 35)) && (!((((*p) == 47) && ((p + 1) < end)) && (p[1] == 47)))) && (p < end))
  {
    p++;
  }

  n = 1;
  {
    register s32 comma = 44;
    register s32 quote = 34;
    register s32 cr = 13;
    do
    {
      s8 *skip = p;
      while ((((*skip) == 32) | ((*skip) == 9)) || ((*skip) == comma))
      {
        if (skip >= end)
        {
          break;
        }
        skip++;
      }

      p = skip;
      if (((*p) == 35) || ((((*p) == 47) && ((p + 1) < end)) && (p[1] == 47)))
      {
        break;
      }
      if (((*p) == 13) | (p >= end))
      {
        break;
      }
      if ((((u8) ((*p) - 48)) < 10) || ((*p) == 45))
      {
        neg = (*p) == 45;
        p += neg;
        ((Token *) work)[n].number = 0;
        ((Token *) work)[n].numeric = 1;
        hex = 0;
        if (((*p) == 48) && (p[1] == 88))
        {
          buf[0] = *p;
          buf[1] = p[1];
          hex = 1;
          p += 2;
        }
        len = 0;
        do
        {
          if (((((*p) == cr) || (((*p) == 32) | ((*p) == 9))) || (i = (*p) == comma)) || (!(p < end)))
          {
            if (hex)
            {
              buf[len + 2] = 0;
            }
            else
            {
              buf[len] = 0;
            }
            break;
          }
          if (hex)
          {
            if (((u8) ((*p) - 48)) >= 10)
            {
              ((Token *) work)[n].number = ((((Token *) work)[n].number * 16) + (*p)) - 55;
            }
            else
            {
              ((Token *) work)[n].number = ((((Token *) work)[n].number * 16) + (*p)) - 48;
            }
            buf[len + 2] = *p;
          }
          else
          {
            ((Token *) work)[n].number = ((((Token *) work)[n].number * 10) + (*p)) - 48;
            buf[len] = *p;
          }
          len++;
          p++;
        }
        while (len < 11);
        if (neg)
        {
          ((Token *) work)[n].text[0] = 45;
          ((Token *) work)[n].number = -((Token *) work)[n].number;
          if (hex)
          {
            func_8008E13C(((Token *) work)[n].text, buf + 1, len + 4);
          }
          else
          {
            func_8008E13C((buf + 72) + (n * 76), buf + 1, len + 2);
          }
        }
        else
          if (hex)
        {
          func_8008E13C((buf + 72) + (n * 76), buf, len + 3);
        }
        else
        {
          func_8008E13C((buf + 72) + (n * 76), buf, len + 1);
        }
      }
      else
      {
        quoted = (*p) == 34;
        p += quoted;
        ((Token *) work)[n].numeric = 0;
        len = 0;
        do
        {
          if (!quoted)
          {
            if (((((*p) == cr) || (((*p) == 32) | ((*p) == 9))) || ((*p) == comma)) || (!(p < end)))
            {
              buf[len] = 0;
              break;
            }
          }
          else
            if ((*p) == quote)
          {
            buf[len] = 0;
            p++;
            break;
          }
          buf[len] = *(p++);
          len++;
        }
        while (len < 65);
        func_8008E13C((buf + 72) + (n * 76), buf, len + 1);
      }
      n++;
    }
    while (n < 27);
    ((Token *) work)[0].number = n - 1;
    i = command * 12;
    if (D_8009CEE9[i] & D_8009E260)
    {
      (*((void (**)(void *)) (((u8 *) D_8009CEE4) + i)))(work);
    }
  }
  return 1;
}
