s32 str_len();
s32 memcpy();
extern s32 LEADERBOARD_FILL_DEFAULT;

/* Fills one entry block from a track record: copies the record's name into the
 * entry, fills the 8 rows x 3 cells table with a constant value, and sets the
 * entry's mode flag bits and two 16-bit fields from the record. */
void fillEntryFromTrackRecord(u8 *record, u8 *entry)
{
#ifdef PORT
  u8 *nameAddr;
#else
  s32 nameAddr;
#endif
  s32 nameLen;
  u32 rowIdx;
  u32 cellIdx;
  s32 rowOffset;
  s32 fillValue;
  u8 *cell;
  s32 mode;
  u8 *new_var;
#ifdef PORT
  nameAddr = record + 0x4C;
#else
  nameAddr = ((s32) record) + 0x4C;
#endif
  nameLen = str_len(nameAddr);
  do { memcpy(entry, nameAddr, nameLen); rowIdx = 0; } while (0);
  fillValue = LEADERBOARD_FILL_DEFAULT;
  rowOffset = 0x2C;
  do
  {
    cellIdx = 0;
    cell = entry + rowOffset;
    do
    {
      *((s32 *) cell) = fillValue;
      cellIdx += 1;
      cell += 0x10;
    }
    while (cellIdx < 3U);
    rowIdx += 1;
    rowOffset += 0x40;
  }
  while (rowIdx < 8U);
  mode = *((s32 *) (record + 0xDC));
  if (mode == 1)
  {
    *((u16 *) (entry + 0x10)) |= 8;
  }
  if (mode == 2)
  {
    *((u16 *) (entry + 0x10)) |= 0x18;
  }
  new_var = record + 0x174;
  *((s16 *) (entry + 0x16)) = *((s32 *) (record + 0x128));
  *((s16 *) (entry + 0x14)) = *((s32 *) new_var);
}
