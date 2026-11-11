extern s32 func_8006B924(u8 *);
extern u8 gStreamState[];
extern u8 D_800A73E0[];

/* For each of three channels, looks up the matching record slot in the table at
 * gStreamState + 0x37E2 / 0x3822 and stores a magnitude-plus-sign delta (clamped to
 * 0x3FFE) and the slot in the 16-bit output words at 0x6FC4; a channel with no
 * slot gets 0xFFFF. */
void UpdateChannelDeltas(void)
{
  u8 *out = gStreamState + 0x6FC4;
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
    slot = func_8006B924((gStreamState + 0x37E2) + off);
    if ((slot & 0xFF) == notFound)
    {
      *((s16 *) (((u32) (row << 1)) + ((u32) out))) = noSlot;
    }
    else
    {
      delta = (*((s32 *) (D_800A73E0 + 0x6B94))) - (*((s32 *) ((gStreamState + 0x37E2) + off)));
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
      *((s16 *) (((u32) ((ch & 0xFF) << 1)) + ((u32) out))) = delta | ((slot & 0xFF) << 14);
      p = nibbles - (-(ch & 0xFF));
      *p = ((*p) & 0xF0) + ((*((gStreamState + 0x37E6) + ((ch & 0xFF) << 4))) & 0xF);
    }
    row = ch & 0xFF;
    off = row << 4;
    slot = func_8006B924((gStreamState + 0x3822) + off);
    if ((slot & 0xFF) == notFound)
    {
      *((s16 *) ((((u32) (row << 1)) + ((u32) out)) + 6)) = noSlot;
    }
    else
    {
      delta = (*((s32 *) (D_800A73E0 + 0x6B98))) - (*((s32 *) ((gStreamState + 0x3822) + off)));
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
      *((s16 *) ((((u32) ((ch & 0xFF) << 1)) + ((u32) out)) + 6)) = delta | ((slot & 0xFF) << 14);
      p = nibbles + (ch & 0xFF);
      *p = ((*p) & 0xF) + (((*((gStreamState + 0x3826) + ((ch & 0xFF) << 4))) & 0xF) << 4);
    }
    ch++;
  }
  while ((ch & 0xFF) < 3);
}
