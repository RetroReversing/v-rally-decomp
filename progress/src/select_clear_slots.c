s32 streamReleaseEntry();
extern s32 gSelectState;

/* Clears the four slot handles at gSelectState+0x184: each non-null handle
   is released through streamReleaseEntry (stream_release_block), then zeroed. */
void select_clear_slots(void)
{
  s32 handle;
  s32 offset;
  s32 i;
  unsigned long new_var;
  i = 0;
  do
  {
    new_var = (i & 0xFF) * 4;
    offset = new_var;
    handle = *((s32 *) (((char *) (offset + gSelectState)) + 0x184));
    if (handle != 0)
    {
      streamReleaseEntry(handle);
    }
    i += 1;
    *((s32 *) (((char *) (offset + gSelectState)) + 0x184)) = 0;
  }
  while (((u32) (i & 0xFF)) < 4U);
}
