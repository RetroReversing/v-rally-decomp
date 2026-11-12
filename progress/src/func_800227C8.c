s32 flag_test_bit0();
s32 flag_clear_bit0();
s32 heapReleaseBlock();
s32 list_for_each();
extern char gOrderState[];
extern char stream_state[];
extern s32 func_80022E64;

/* If the order-state block at +0x7320 is ready, hands each entry of the stream
 * table at +0x7162 to list_for_each with the shared callback, then releases the
 * entry through heapReleaseBlock, and finally calls flag_clear_bit0 on the block. */
void func_800227C8(void)
{
  s32 *entry;
  s32 entry_value;
  s32 count;

  if (flag_test_bit0(gOrderState + 0x7320) != 0)
  {
    count = 0;
    entry = (s32 *) (stream_state + 0x7162);
    do
    {
      count += 1;
      list_for_each(*entry, &func_80022E64);
      entry_value = *entry;
      entry += 1;
      heapReleaseBlock(entry_value);
    }
    while (count == 0);
    flag_clear_bit0(gOrderState + 0x7320);
  }
}
