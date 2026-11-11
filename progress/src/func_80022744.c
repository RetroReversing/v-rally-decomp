s32 flag_test_bit0();
s32 func_80022F98();
extern s32 gPadFlags;
extern char gOrderState[];
extern char gStreamState[];

/* When pad flag bit 2 is clear and the order-state check at +0x7320 passes, passes the
 * first word at gStreamState+0x7162 to func_80022F98. */
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
      word_ptr = (s32 *) (gStreamState + 0x7162);
      do
      {
        word = *word_ptr;
        word_ptr++;
        func_80022F98(word);
        count++;
      }
      while (count == 0);
    }
  }
}
