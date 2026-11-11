s32 streamFreeObject();

/* Stores `first` in the stream's slot +0x20. If both `first` and `second` are set, the old objects
 * in +0x20 and +0x24 are freed and both slots are replaced, and the record is flagged with 2 at +0x28.
 * Otherwise +0x24 is set to `first`. */
void stream_set_objects(void *stream, s32 first, s32 second)
{
  s32 old_first;
  old_first = *((s32 *) (((char *) stream) + 0x20));
  if ((first != 0) & (second != 0))
  {
    goto replace;
  }
  *((s32 *) (((char *) stream) + 0x20)) = first;
  goto set_second;
  replace:
  streamFreeObject(old_first);

  *((s32 *) (((char *) stream) + 0x20)) = 0;
  streamFreeObject(*((s32 *) (((char *) stream) + 0x24)));
  *((s32 *) (((char *) stream) + 0x24)) = 0;
  *((s32 *) (((char *) stream) + 0x20)) = first;
  *((s32 *) (((char *) stream) + 0x24)) = second;
  *((u16 *) (((char *) stream) + 0x28)) |= 2;
  return;
  set_second:
  *((s32 *) (((char *) stream) + 0x24)) = first;

  return;
}
