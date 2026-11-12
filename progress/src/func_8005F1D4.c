extern unsigned short D_800C3556;
s32 slotSetSelected();
extern char stream_state[];

/* Toggles bit 0 of the stream state halfword at +0x32A8, then calls
 * slotSetSelected with the low bit of D_800C3556. Always returns 0. */
s32 func_8005F1D4(s32 slot)
{
  u16 *flags;
  u16 value;
  u16 cur;
  flags = stream_state + 0x32A8;
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
  flags = stream_state + 0x32A8;
  #ifdef PORT
  slotSetSelected(slot, D_800C3556 & 1);
#else
  flags = (u16 *) D_800C3556;
  flags = (u16 *) (((s32) flags) & 1);
  slotSetSelected(slot, flags);
#endif
  value = 0;
  return 0;
}
