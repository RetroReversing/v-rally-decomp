#ifdef PORT
extern u8 *gOrderSlotTable;
#else
extern int gOrderSlotTable;
#endif

/* Burns a 16-step counter loop, then if gOrderSlotTable is set, copies four per-channel
 * s32 fields from each 0x130-byte channel record in arg0 into the table at +0x40..+0x4C. */
void func_8001D720(void *channels)
{
  s32 ch;
  u8 idx;
  char *chan;
#ifdef PORT
#else
  s32 table;
#endif

  chan = channels;
  ch = 1;
  do
  {
    ch++;
  }
  while ((u32) (ch & 0xFF) < 0x11U);
  if (gOrderSlotTable != 0)
  {
    ch = 0;
    do
    {
#ifdef PORT
      idx = ch & 0xFF;
      *((s8 *) (gOrderSlotTable + idx + 0x40)) = *((s32 *) (chan + idx * 0x130 + 0x90));
      *((s8 *) (gOrderSlotTable + idx + 0x44)) = *((s32 *) (chan + idx * 0x130 + 0xDC));
      *((s8 *) (gOrderSlotTable + idx + 0x48)) = *((s32 *) (chan + idx * 0x130 + 0x128));
      *((s8 *) (gOrderSlotTable + idx + 0x4C)) = *((s32 *) (chan + idx * 0x130 + 0x174));
#else
      table = gOrderSlotTable;
      idx = ch & 0xFF;
      *((s8 *) (table + idx + 0x40)) = *((s32 *) (chan + idx * 0x130 + 0x90));
      *((s8 *) (gOrderSlotTable + idx + 0x44)) = *((s32 *) (chan + idx * 0x130 + 0xDC));
      *((s8 *) (gOrderSlotTable + idx + 0x48)) = *((s32 *) (chan + idx * 0x130 + 0x128));
      *((s8 *) (gOrderSlotTable + idx + 0x4C)) = *((s32 *) (chan + idx * 0x130 + 0x174));
#endif
      ch++;
    }
    while ((u32) (ch & 0xFF) < 4U);
  }
}
