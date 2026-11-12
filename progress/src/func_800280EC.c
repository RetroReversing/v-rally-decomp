s32 seq_record_store_u32(s32, s32);
s32 func_80027CFC(s32);
s32 seq_next_entry(void *);
extern char *gSlotTable;

/* If the slot's flag word (at +8 of its 0x44-byte entry, selected by the byte at +3 of
 * the object's sub-record) has bit 0x10 set, advances the sequence entry and runs the two follow-up steps. */
void func_800280EC(void **obj, s32 arg1)
{
  u16 *slot_flags;
  if ((*(slot_flags = (u16 *) (((char *) (gSlotTable + (0x44 * (*((u8 *) (((char *) (*((void **) (((char *) (*obj)) + 0x48)))) + 3)))))) + 8))) & 0x10)
  {
    seq_record_store_u32(seq_next_entry(gSlotTable), arg1);
    func_80027CFC(arg1);
  }
}
