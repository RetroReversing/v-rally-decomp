s32 func_8007F73C();
s32 osInvalDCache();
s32 osPiStartDma();
s32 osRecvMesg();
s32 osSendMesg();
extern char gOrderState[];
extern char gStreamState[];

/* DMA request loop: waits on the request queue in gStreamState, invalidates the cache for the
 * request's buffer, starts a PI DMA (size rounded up to 8 bytes) and posts the completion
 * message back to the request's reply queue. Never returns. */
void dma_thread_main(void)
{
  void *req;
  s32 sizeMask;
  void *piHandle;
  sizeMask = -8;
  piHandle = gOrderState + 0x65B8;
  sizeMask = ~7;
  loop_1:
  osRecvMesg(gStreamState + 0x768A, &req, 1);

  osInvalDCache(*((s32 *) (((char *) req) + 4)), *((s32 *) (((char *) req) + 8)));
  osPiStartDma(req + 0xC, 0, 0, *((s32 *) (((char *) req) + 0)), *((s32 *) (((char *) req) + 4)), ((*((s32 *) (((char *) req) + 8))) + 7) & sizeMask, piHandle);
  func_8007F73C(0x22, 1);
  osSendMesg(req + 0x24, req + 0x3C, 1);
  goto loop_1;
}
