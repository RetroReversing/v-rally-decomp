s32 func_800857EC();
s32 func_800858A4();
extern char *gContCtx;

/* Sends command param to controller channel on slot, once that channel's status
   record (gContCtx + channel*4 + 0x38C) reports ready (state 2). Returns 1 if the
   command was issued, 0 otherwise. */
s32 cont_issue_command(s32 channelArg, s32 slotArg, s32 paramArg)
{
  s32 channel;
  s32 entry;
  s32 node;
  s32 state;
  channel = channelArg & 0xFF;
  if (func_800858A4(channel, slotArg & 0xFF, 0) != 0)
  {
    entry = *((s32 *) ((gContCtx + (channel * 4)) + 0x38C));
    if ((*((s32 *) (entry + 8))) != 2)
    {
      node = entry;
      entry = 2;
      do
      {
        state = *((vs32 *) (node + 8));
      }
      while (state != entry);
    }
    if (func_800857EC(channelArg & 0xFF, slotArg & 0xFF, paramArg & 0xFF) != 0)
    {
      return 1;
    }
  }
  return 0;
}
