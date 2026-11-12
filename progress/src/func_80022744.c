s32 flag_test_bit0();
s32 stream_run_entry_callbacks();
extern s32 gPadFlags;
extern char gOrderState[];
extern char stream_state[];

/* When pad flag bit 2 is clear and the order-state check at +0x7320 passes, passes the
 * first word at stream_state+0x7162 to stream_run_entry_callbacks. */
void func_80022744(void)
{
  s32 *word_ptr;
  s32 count;
  s32 word;

  if (!(gPadFlags & 2))
  {
    if (flag_test_bit0(gOrderState + 0x7320) != 0)
    {
      count = 0;
      word_ptr = (s32 *) (stream_state + 0x7162);
      do
      {
        word = *word_ptr;
        word_ptr++;
        stream_run_entry_callbacks(word);
        count++;
      }
      while (count == 0);
    }
  }
}
