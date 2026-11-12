extern s32 D_800A3B40;
extern u8 stream_state[];
extern u8 __osPfsLastCmd;
extern s32 osRecvMesg(s32, void *, s32);
extern void pif_lock(void);
extern void pif_unlock(void);
extern void __osSiRawStartDma(s32, void *);
extern void __osCopyBytes(void *, void *, s32);
extern s32 __osContAddressCrc(u32);
extern s32 __osContDataCrc(void *);
extern u32 getPakStatus(s32, s32);

/* libultra __osContRamWrite: writes 32 bytes to controller pak RAM at `address`
 * on `channel`. Builds the command block in the shared PIF buffer, sends it and
 * checks the data CRC; a CRC mismatch retries up to three times. Returns 0 for
 * an invalid address, otherwise the controller status (0 = ok). */
u32 __osContRamWrite(s32 mq, s32 channel, u16 address, void *buf, s32 force)
{
  u8 scratch[8];
  u8 *cmd = stream_state + 0x7e82;
  s32 retries = 2;
  s32 data_crc;
  u32 ret;
  s32 n;
  u32 addr;
  if ((force != 1) & (((u32) address) < 7U))
  {
    if (address != 0)
    {
      return 0;
    }
  }
  pif_lock();
  if ((__osPfsLastCmd != 3) || (D_800A3B40 != channel))
  {
    stream_state[0x3272] = 3;
    D_800A3B40 = channel;
    n = 0;
    if (channel > 0)
    {
      do
      {
        *(cmd++) = 0;
        n++;
      }
      while (n < channel);
    }
    *((s32 *) (stream_state + 0x7ebe)) = 1;
    cmd[0] = (n = 255);
    cmd[1] = 0x23;
    cmd[2] = 1;
    cmd[3] = 3;
    cmd[0x26] = n;
    cmd[0x27] = 254;
  }
  else
  {
    cmd += channel;
  }
  addr = address & 0xffff;
  cmd[4] = addr >> 3;
  cmd[5] = __osContAddressCrc(addr) | (address << 5);
  __osCopyBytes(buf, cmd + 6, 32);
  __osSiRawStartDma(1, stream_state + 0x7e82);
  data_crc = __osContDataCrc(buf);
  osRecvMesg(mq, 0, 1);
  do
  {
    __osSiRawStartDma(0, stream_state + 0x7e82);
    osRecvMesg(mq, 0, 1);
    ret = (cmd[2] & 0xc0) >> 4;
    if (ret == 0)
    {
      if (((u32) (data_crc & 255)) != cmd[0x26])
      {
        ret = getPakStatus(mq, channel);
        if (ret != 0)
        {
          break;
        }
        ret = 4;
      }
    }
    else
    {
      ret = 1;
    }
  }
  while ((ret == 4) && ((retries--) >= 0));
  pif_unlock();
  return ret;
}
