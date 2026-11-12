extern void *gRecords;

static inline u8 slotByte8(void *slot)
{
  return *((u8 *) (((s8 *) slot) + 8));
}

static inline s8 *recordEntryAddr(void *table, int index)
{
  return (s8 *)table + (index * 0x28);
}

/* Checks the slot's id bytes (+6, +7, +8) against stream record `index` (0x28 bytes each, id at +0x44..+0x46).
 * On a match it clears the slot's pending flag (+0xC) and returns 1; otherwise returns 0. */
s32 record_item_match_clear(void *arg0, s32 arg1)
{
  void *temp_a0;
  s8 *new_var;
  if ((*((u8 *) (((s8 *) arg0) + 0xC))) != 0)
  {
    ;
    new_var = (s8 *) arg0;
    if ((((*((u8 *) (((s8 *) arg0) + 6))) == (*((u8 *) (((s8 *) recordEntryAddr(gRecords, arg1 & 0xFF)) + 0x44)))) && ((*((u8 *) (new_var + 7))) == (*((u8 *) (((s8 *) recordEntryAddr(gRecords, arg1 & 0xFF)) + 0x45))))) && (slotByte8(arg0) == (*((u8 *) (((s8 *) recordEntryAddr(gRecords, arg1 & 0xFF)) + 0x46)))))
    {
      *((u8 *) (((s8 *) arg0) + 0xC)) = 0U;
      return 1;
    }
    return 0;
  }
  return 0;
}
