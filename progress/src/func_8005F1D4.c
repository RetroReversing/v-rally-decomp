extern unsigned short D_800C3556;
s32 slot_set_selected();
extern char gStreamState[];

/* Toggles bit 0 of the stream state halfword at +0x32A8, then calls
 * slot_set_selected with the low bit of D_800C3556. Always returns 0. */
s32 func_8005F1D4(s32 slot)
{
  u16 *flags;
  u16 value;
  u16 cur;
  flags = gStreamState + 0x32A8;
  cur = *flags;
  value = cur & 1;
  if (!(value == 0))
  {
    value = cur & 0xFFFE;
  }
  else
  {
    value = cur | 1;
  }
  *flags = value;
  flags = gStreamState + 0x32A8;
  flags = (u16 *) D_800C3556;
  flags = (u16 *) (((s32) flags) & 1);
  slot_set_selected(slot, flags);
  value = 0;
  return 0;
}
