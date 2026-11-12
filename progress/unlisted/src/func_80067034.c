extern void *gSelectState;
extern s32 gRecords;
void slot_set_selected(s32 index, s32 flag);

/* Pushes the four low flag bits of the selected record (byte 0x48) into the sub-slot flags for ids 0x1C..0x1F. */
void func_80067034(void)
{
  s32 recOff;

  recOff = *((u8 *) ((char *) gSelectState + 0x22A)) * 0x28;
  slot_set_selected(0x1C, *((u8 *) (gRecords + recOff + 0x48)) & 1);
  slot_set_selected(0x1D, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 1 & 1);
  slot_set_selected(0x1E, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 2 & 1);
  slot_set_selected(0x1F, ((u8) *((u8 *) (gRecords + recOff + 0x48))) >> 3 & 1);
}
