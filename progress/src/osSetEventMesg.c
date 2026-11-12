s32 osDisableInt();
void osRestoreInt(s32);
extern char stream_state[];

/* Stores the two message words for event arg0 (8-byte entries at stream_state+0x75FA), with interrupts disabled. */
void osSetEventMesg(s32 event, s32 msg0, s32 msg1)
{
  s32 saved;
  void *entry;
  saved = osDisableInt();
  entry = (event * 8) + (stream_state + 0x75FA);
  *((s32 *) (((char *) entry) + 0)) = msg0;
  *((s32 *) (((char *) entry) + 4)) = msg1;
  osRestoreInt(saved);
}
