s32 slot_set_selected();
s32 select_stream_char();
extern void *gSelectState;
extern void *gRecords;

/* Looks up the current select-screen entry in gRecords, picks a slot from its hash bytes,
 * and if the slot's value (+0x1C) is below 20 raises it by 10 and refreshes the display. */
s32 func_8006B220(s32 arg0)
{
  s32 pad;
  char *slot;
  char *entry;
  int slotOffset;
  char *base;
  s16 value;
  s16 newValue;
  base = (char *) gRecords;
  entry = base + ((((u8 *) (base + (*((s8 *) (((char *) gSelectState) + 0x228)))))[0x32] * 0x28) + 0x44);
  slot = entry + ((select_stream_char(((u8 *) base)[0x1F], ((u8 *) base)[0x21], ((u8 *) base)[0x23]) & ((long long) 0xFF)) * 2);
  value = *((s16 *) (slot + 0x1C));
  slotOffset = 0x1C;
  newValue = value;
  if (value < 0x14)
  {
    newValue = value + 0xA;
    *((s16 *) (slot + slotOffset)) = newValue;
    slot_set_selected(arg0, (-((s16) (newValue / 10))) + 2, slot);
  }
  return 1;
}
