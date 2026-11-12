extern s32 func_8006B924(u8 *);
extern u8 stream_state[];
extern u8 gGameState[];

/* For each of three channels, looks up the matching record slot in the table at
 * stream_state + 0x37E2 / 0x3822 and stores a magnitude-plus-sign delta (clamped to
 * 0x3FFE) and the slot in the 16-bit output words at 0x6FC4; a channel with no
 * slot gets 0xFFFF. */
void UpdateChannelDeltas(void)
{
  u8 *out = stream_state + 0x6FC4;
  u8 *nibbles = out - 3;
  u8 ch = 0;
  s32 notFound = 5;
  s32 noSlot = 0xFFFF;
  s32 magMask = -2;
  s32 row;
  s32 off;
  s32 delta;
  s32 slot;
  u8 *p;
  do
  {
    row = ch;
    off = row << 4;
    slot = func_8006B924((stream_state + 0x37E2) + off);
    if ((slot & 0xFF) == notFound)
    {
#ifdef PORT
      *((s16 *) (out + (row << 1))) = noSlot;
#else
      *((s16 *) (((u32) (row << 1)) + ((u32) out))) = noSlot;
#endif
    }
    else
    {
      delta = (*((s32 *) (gGameState + 0x6B94))) - (*((s32 *) ((stream_state + 0x37E2) + off)));
      if (delta >= 0)
      {
        if (delta >= 0x4000)
        {
          delta = 0x3FFE;
        }
        delta &= magMask;
      }
      else
      {
        delta = -delta;
        if (delta >= 0x4000)
        {
          delta = 0x3FFE;
        }
        delta |= 1;
      }
#ifdef PORT
      *((s16 *) (out + ((ch & 0xFF) << 1))) = delta | ((slot & 0xFF) << 14);
#else
      *((s16 *) (((u32) ((ch & 0xFF) << 1)) + ((u32) out))) = delta | ((slot & 0xFF) << 14);
#endif
      p = nibbles - (-(ch & 0xFF));
      *p = ((*p) & 0xF0) + ((*((stream_state + 0x37E6) + ((ch & 0xFF) << 4))) & 0xF);
    }
    row = ch & 0xFF;
    off = row << 4;
    slot = func_8006B924((stream_state + 0x3822) + off);
    if ((slot & 0xFF) == notFound)
    {
#ifdef PORT
      *((s16 *) (out + (row << 1) + 6)) = noSlot;
#else
      *((s16 *) ((((u32) (row << 1)) + ((u32) out)) + 6)) = noSlot;
#endif
    }
    else
    {
      delta = (*((s32 *) (gGameState + 0x6B98))) - (*((s32 *) ((stream_state + 0x3822) + off)));
      if (delta >= 0)
      {
        if (delta >= 0x4000)
        {
          delta = 0x3FFE;
        }
        delta &= magMask;
      }
      else
      {
        delta = -delta;
        if (delta >= 0x4000)
        {
          delta = 0x3FFE;
        }
        delta |= 1;
      }
#ifdef PORT
      *((s16 *) (out + ((ch & 0xFF) << 1) + 6)) = delta | ((slot & 0xFF) << 14);
#else
      *((s16 *) ((((u32) ((ch & 0xFF) << 1)) + ((u32) out)) + 6)) = delta | ((slot & 0xFF) << 14);
#endif
      p = nibbles + (ch & 0xFF);
      *p = ((*p) & 0xF) + (((*((stream_state + 0x3826) + ((ch & 0xFF) << 4))) & 0xF) << 4);
    }
    ch++;
  }
  while ((ch & 0xFF) < 3);
}
