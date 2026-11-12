extern int D_800AFA6C;
extern int D_800B4144;
extern int D_800C7308;
extern int D_800B56C0;
s32 func_80005890();
s32 taskOpen();
s32 create_thread_on_ctx();
extern s32 D_8009B6E0;
extern s32 *gPrevVideoHandler;
extern char gOrderState[];
extern char stream_state[];
extern s32 *D_800C80C0;
extern s32 video_blank_on_exit;
extern s32 displayLoop;

/* Installs video_blank_on_exit as the active handler, keeping the previous one in gPrevVideoHandler.
 * When the init check (func_80005890) passes, it resets D_800AFA6C and creates the two
 * handles D_800B4144 and D_800C7308, plus D_800B56C0 for &displayLoop. Returns 1 when
 * the check passed and D_8009B6E0 is set, else 0. */
s32 func_8000D9CC(void)
{
  s32 *prevHandler;
  s32 handle;
  s32 ready;
  s32 result;
  prevHandler = D_800C80C0;
  D_800C80C0 = (s32 *) &video_blank_on_exit;
  gPrevVideoHandler = prevHandler;
  ready = func_80005890() & 0xFF;
  if (ready != 0)
  {
    D_800AFA6C = 0;
    D_800B4144 = taskOpen(4, 0, 1);
    handle = taskOpen(6, 0, 1);
    D_800C7308 = handle;
    D_800B56C0 = create_thread_on_ctx(&displayLoop, 0x400, 0x74, handle);
  }
  result = 0;
  if (ready != 0)
  {
    result = D_8009B6E0 != 0;
  }
  return result;
}
