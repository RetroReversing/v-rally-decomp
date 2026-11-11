extern char gStreamState[];
s32 osRecvMesg();

/* Message-loop thread body: waits on the message queue at +0x14, then jumps to the handler indexed by the message's word at +0xE (table at gStreamState+0x7D8A). Never returns. */
void func_8007F490(void *thread)
{
  s32 msg;
  void (*handler)();
 do { } while (0);
  osRecvMesg(((char *) thread) + 0x14, &msg, 1);
  handler = *((void (**)()) ((gStreamState + 0x7D8A) + ((*((u16 *) (((char *) thread) + 0xE))) * 4)));
  handler();
  while (1)
  {
  }
}
