typedef struct 
{
  u8 pad0[0x228];
  s8 cur;
  u8 pad229;
  s8 want;
  s8 b22B;
  u8 pad22C[0x245 - 0x22C];
  u8 b245;
  u8 pad246[0x24D - 0x246];
  u8 b24D;
  u8 b24E;
  u8 pad24F[0x288 - 0x24F];
  void (*f288)(void);
  void (*f28C)(void);
} State;
extern State *gSelectState;
extern u8 *gRecords;
void select_reset_text(s32, s32);
void select_init_screen(void);
void func_80066EBC(void);

/* Resets the selection state, then, when the wanted slot for the current
 * player changes, moves the player to it. gRecords[0x32 + i] holds slot i's
 * assignment; a clash with another player's slot is resolved by swapping in
 * the free value (or the old one) so that every player keeps a unique slot. */
s32 func_80069734(void)
{
  u8 taken[4] = {0, 0, 0, 0};
  State *st;
  u8 old;
  u8 *recs;
  u8 i;
  State *s;
  select_reset_text(0, 0);
  s = gSelectState;
  s->b245 = 0;
  s->f288 = select_init_screen;
  s->f28C = func_80066EBC;
  st = gSelectState;
  st->b24D = 0;
  s = gSelectState;
  s->b22B = -1;
  st = gSelectState;
  recs = gRecords;
  old = *(recs + st->cur + 0x32);
  if (old != st->want)
  {
    s8 w = st->want;
    (gRecords + st->cur)[0x32] = w;
    i = 0;
    if (gRecords[0x32] == gRecords[0x33])
    {
      do
      {
        taken[(gRecords + i)[0x32]] = 1;
        i++;
      }
      while (i < 4);
      for (i = 0; i < 4; i++)
      {
        if (taken[i] == 0)
        {
          break;
        }
      }

      gRecords[0x33] = i;
    }
    else
    {
      for (; i < 4; i++)
      {
        if ((i != gSelectState->cur) && ((gRecords + i)[0x32] == gSelectState->want))
        {
          break;
        }
      }

      (gRecords + i)[0x32] = old;
    }
  }
  gSelectState->b24E = 0;
  s = gSelectState;
  s->b245 = 0;
  return 0;
}
