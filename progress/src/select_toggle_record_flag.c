extern char *gRecords;
void slotSetSelected(s32 slot, s32 index);
extern void *gSelectState;

/* Toggles bit 3 of the flags byte (+0x48) of the currently selected record (0x28 bytes each),
 * then re-selects slot 0x1F with the new value of that bit. */
s32 select_toggle_record_flag(void)
{
  u8 flags;
  u8 newFlags;
  char *rec;
  void *record;

  record = gRecords + ((*((s8 *) (((char *) gSelectState) + 0x22A))) * 0x28);
  flags = *((u8 *) (((char *) record) + 0x48));
  if (flags & 8)
  {
    newFlags = flags & 0xF7;
  }
  else
  {
    newFlags = flags | 8;
  }
  *((u8 *) (((char *) record) + 0x48)) = newFlags;
  rec = ((char *) (gRecords + ((*((s8 *) (((char *) gSelectState) + 0x22A))) * 0x28))) + 0x48;
  slotSetSelected(0x1F, (((u8) (*((u8 *) rec))) >> 3) & 1);
  return 0;
}
