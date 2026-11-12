s32 taskOpen();
s32 func_8007F634();
s32 taskRecvMsg();
extern void *gControllerInputContext;

/* Opens task 4's message queue, clears bit 0 of the controller flag byte at 0x39C,
 * then receives on the queue and closes the task handle. */
void func_80084AFC(void)
{
  s32 handle;
  s32 queue;
  int flags;
  handle = taskOpen(4, 0, 8);
  queue = handle;
  flags = (*((u8 *) (((char *) gControllerInputContext) + 0x39C))) & 0xFE;
  *((u8 *) (((char *) gControllerInputContext) + 0x39C)) = flags;
  taskRecvMsg(queue, flags);
  func_8007F634(handle);
}
