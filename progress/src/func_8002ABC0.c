extern void memcpy(void *, void *, s32);
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
typedef struct
{
  void (*fn)(void *);
  u8 unk4;
  u8 flags;
  u8 pad[6];
} CmdEntry;

/* Parses one command line of script text starting at `text` (stops at `end`):
 * splits it into up to 26 comma/space separated tokens (numbers, hex 0x.. or
 * quoted strings, stored in tokens[1..]; tokens[0].number holds the count), then
 * calls the command's handler when its flag bit is set. cmd_id is the 1-based
 * command index. Always returns 1. */
s32 func_8002ABC0(s32 cmd_id, s8 *text, s8 *end)
{
  s8 buf[72];
  Token tokens[26];
  s16 n;
  s16 len;
  u8 neg;
  u8 hex;
  s16 quoted;
  u32 i;
  s32 command;
  cmd_id--;
  command = cmd_id;
  while (((((((*text) != 32) & ((*text) != 9)) && (((*text) != 44) & ((*text) != 13))) && ((*text) != 35)) && (!((((*text) == 47) && ((text + 1) < end)) && (text[1] == 47)))) && (text < end))
  {
    text++;
  }

  n = 1;
  {
    register s32 comma = 44;
    register s32 quote = 34;
    do
    {
      s8 *skip = text;
      while ((((*skip) == 32) | ((*skip) == 9)) || ((*skip) == comma))
      {
        if (skip >= end)
        {
          break;
        }
        skip++;
      }

      text = skip;
      if (((*text) == 35) || ((((*text) == 47) && ((text + 1) < end)) && (text[1] == 47)))
      {
        break;
      }
      if (((*text) == 13) | (text >= end))
      {
        break;
      }
      if ((((u8) ((*text) - 48)) < 10) || ((*text) == 45))
      {
        neg = (*text) == 45;
        text += neg;
        tokens[n].number = 0;
        tokens[n].numeric = 1;
        hex = 0;
        if (((*text) == 48) && (text[1] == 88))
        {
          buf[0] = *text;
          buf[1] = text[1];
          hex = 1;
          text += 2;
        }
        len = 0;
        do
        {
          if (((((*text) == 13) || (((*text) == 32) | ((*text) == 9))) || (i = (*text) == comma)) || (!(text < end)))
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
            if (((u8) ((*text) - 48)) >= 10)
            {
              tokens[n].number = ((tokens[n].number * 16) + (*text)) - 55;
            }
            else
            {
              tokens[n].number = ((tokens[n].number * 16) + (*text)) - 48;
            }
            buf[len + 2] = *text;
          }
          else
          {
            tokens[n].number = ((tokens[n].number * 10) + (*text)) - 48;
            buf[len] = *text;
          }
          len++;
          text++;
        }
        while (len < 11);
        if (neg)
        {
          tokens[n].text[0] = 45;
          tokens[n].number = -tokens[n].number;
          if (hex)
          {
            #ifdef PORT
memcpy((s8 *) (buf + n * 76) + 72, buf + 1, len + 4);
#else
memcpy((s8 *) ((n * 76) + (s32) buf) + 72, buf + 1, len + 4);
#endif
          }
          else
          {
            #ifdef PORT
memcpy((s8 *) (buf + n * 76) + 72, buf + 1, len + 2);
#else
memcpy((s8 *) ((n * 76) + (s32) buf) + 72, buf + 1, len + 2);
#endif
          }
        }
        else
          if (hex)
        {
          #ifdef PORT
memcpy((s8 *) (buf + n * 76) + 72, buf, len + 3);
#else
memcpy((s8 *) ((n * 76) + (s32) buf) + 72, buf, len + 3);
#endif
        }
        else
        {
#ifdef PORT
          memcpy((s8 *) (buf + n * 76) + 72, buf, len + 1);
#else
          memcpy((s8 *) ((n * 76) + (s32) buf) + 72, buf, len + 1);
#endif
        }
      }
      else
      {
        quoted = (*text) == 34;
        text += quoted;
        tokens[n].numeric = 0;
        for (len = 0; len < 65; len++)
        {
          if (quoted)
          {
            if ((*text) == 34)
            {
              buf[len] = 0;
              text++;
              break;
            }
          }
          else
          {
            if (((((*text) == 13) || (((*text) == 32) | ((*text) == 9))) || (i = (*text) == comma)) || (!(text < end)))
            {
              buf[len] = 0;
              break;
            }
          }
          buf[len] = *(text++);
        }
#ifdef PORT
        memcpy((s8 *) (buf + n * 76) + 72, buf, len + 1);
#else
        memcpy((s8 *) ((n * 76) + (s32) buf) + 72, buf, len + 1);
#endif
      }
      n++;
    }
    while (n < 27);
    tokens[0].number = n - 1;
    if (D_8009CEE9[cmd_id * 12] & D_8009E260)
    {
      D_8009CEE4[cmd_id * 3](tokens);
    }
  }
  return 1;
}
