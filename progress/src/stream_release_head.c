volatile long stream_run_entry_callbacks(s32);
extern s32 D_800C7410;
/* Runs the entry callbacks for each object pointer in the stream head table (D_800C7410), stopping after the first pass. */ void stream_release_head(void)
{
  s32 *cursor;
  int step;
  s32 obj;
  s32 count;
  count = 0;
  cursor = &D_800C7410;
  do
  {
    obj = *cursor;
    step = 4;
    step = 1;
    cursor += step;
    count += step;
    stream_run_entry_callbacks(obj);
  }
  while (count == 0);
}
