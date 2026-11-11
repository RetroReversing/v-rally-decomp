extern u8 *gContCtx;

/* Zeroes the 14 words at +0xAC of controller context entry `slot` (0x38 bytes per entry). */
void contClearEntryWords(u8 slot)
{
  int tailOffset;
  u8 i;
  u8 *base;
  u32 *entry;
  base = gContCtx;
  entry = (u32 *) (base + (slot * 0x38));
  ;
  i = 0;
  do
  {
    tailOffset = 0xAC;
    ((u32 *) (((u8 *) ((u32 *) (base + (14 * (4 * slot))))) + tailOffset))[i] = 0;
    i++;
  }
  while (i < 0xE);
}
