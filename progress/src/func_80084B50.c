/* identical to func_8008A480 in V-RALLY (matched), with its names changed by decompdecomp */
/* identical to func_80084B50 in V-RALLY (matched), with its names changed by decompdecomp */

s32 taskOpen();
s32 func_8007F634();
s32 taskRecvMsg();
extern void *gContCtx;
void func_80084B50(void)
{
  s32 temp_a0;
  s32 temp_s0;
  int temp_a1;
  temp_s0 = taskOpen(4, 0, 8);
  temp_a0 = temp_s0;
  temp_a1 = (*((u8 *) (((char *) gContCtx) + 0x39C))) | 1;
  *((u8 *) (((char *) gContCtx) + 0x39C)) = temp_a1;
  taskRecvMsg(temp_a0, temp_a1);
  func_8007F634(temp_s0);
}
