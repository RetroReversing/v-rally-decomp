extern u16 gOrderCursor;
extern u16 D_800B0C66;
extern char gOrderState[];
s32 seq_record_store_u32();
s32 func_80027CFC();

/* Takes the next entry from the order table (its pointer is at +0x240C of gOrderState),
 * advances the cursor while it is below the limit in D_800B0C66, then sends the entry. */
void order_next_entry_send(s32 arg0, void *arg1)
{
  u16 cursor;
  u32 limit;
  s32 *table;
  s32 *new_var;
  s32 entry;
  cursor = gOrderCursor;
  table = *((s32 **) (gOrderState + 0x240C));
  new_var = &table[cursor];
  limit = D_800B0C66;
  entry = *new_var;
  if (cursor < limit)
  {
    gOrderCursor = cursor + 1;
  }
  seq_record_store_u32(entry, arg1);
  func_80027CFC(arg1);
}
