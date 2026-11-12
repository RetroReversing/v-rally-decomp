/* Stores value at +0x10 of record slot index, where slots are 20 bytes apart in the table at +0x10 of rec. */ void setRecordSlotValue(void *rec, s32 index, s32 value)
{
#ifdef PORT
  s8 *slot;
  slot = (*((s8 **) (((s8 *) rec) + 0x10))) + (((index & 0xFFFF) * 4) * 5);
  *((s32 *) (slot + 0x10)) = value;
#else
  int slot;
  slot = (*((s32 *) (((s8 *) rec) + 0x10))) + (((index & 0xFFFF) * 4) * 5);
  *((s32 *) (((s8 *) slot) + 0x10)) = value;
#endif
}
