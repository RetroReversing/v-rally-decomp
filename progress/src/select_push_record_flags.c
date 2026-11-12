extern void *gSelectState;
#ifdef PORT
extern u8 *gRecords;
#else
extern s32 gRecords;
#endif
void slotSetSelected(s32 index, s32 flag);

/* Pushes the four low flag bits of the selected record (byte 0x48) into the sub-slot flags for ids 0x1C..0x1F. */
void select_push_record_flags(void)
{
  s32 recOff;

  recOff = *((u8 *) ((char *) gSelectState + 0x22A)) * 0x28;
  slotSetSelected(0x1C, *((u8 *) (gRecords + recOff + 0x48)) & 1);
  slotSetSelected(0x1D, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 1 & 1);
  slotSetSelected(0x1E, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 2 & 1);
  slotSetSelected(0x1F, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 3 & 1);
}
