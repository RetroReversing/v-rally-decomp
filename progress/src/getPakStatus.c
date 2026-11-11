extern s8 D_800A3B34;
extern u8 D_800C8130;
extern s32 __osSiRawStartDma(s32, void *);
extern s32 __osPfsRequestOneChannel(s32);
extern s32 __osPfsGetOneChannelData(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);

/* Reads the status of the controller pak on the given channel: asks the pak for
 * its data and returns a code: 2 when the status reports both busy bits, 1
 * when the pak id is not 0x100, 4 when the flag bit 4 is set, and otherwise
 * the result of the first request (0 on success). */
s32 getPakStatus(s32 mq, s32 channel)
{
  int timeout;
  s32 status[2];
  s32 msg[2];
  s32 result;
  void *buf;
  timeout = 250;
  D_800A3B34 = timeout;
  __osPfsRequestOneChannel(channel);
  buf = &D_800C8130;
  __osSiRawStartDma(1, buf);
  osRecvMesg(mq, msg, 1);
  result = __osSiRawStartDma(0, buf);
  osRecvMesg(mq, msg, 1);
  __osPfsGetOneChannelData(channel, status);
  if ((((u8 *) status)[2] & 1) && (((u8 *) status)[2] & 2))
  {
    return 2;
  }
  if ((((u16 *) status)[1] & 0x1ff) != 0x100)
  {
    return 1;
  }
  if (((u8 *) status)[2] & 4)
  {
    return 4;
  }
  return result;
}
