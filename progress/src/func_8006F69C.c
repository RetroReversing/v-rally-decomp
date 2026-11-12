s32 stream_header_is_valid();
s32 func_8006F628();
s32 crc32_compute();
s32 func_80084AFC();
s32 func_80084B50();
s32 pakReadBlock();
extern s32 gRaceFlags;
extern char gOrderState[];
extern char stream_state[];

/* Loads the save index from the controller pak when gRaceFlags bit 0x8000 is clear: reads its 64 eight-byte
 * entries from gOrderState+0x5A38 into stream_state+0x6E22, then checks the index checksum (over 0x1FC bytes)
 * against the stored value. On a mismatch it runs the recovery steps. Returns the last block read's result. */
s32 func_8006F69C(void)
{
  s32 result;
  s32 needRecovery;
  s32 i;
  s32 flags;
  void *index;
  flags = gRaceFlags & 0x8000;
  if (flags == 0)
  {
    index = stream_state + 0x6E22;
    i = 0;
    func_80084AFC();
    do
    {
      result = pakReadBlock(gOrderState + 0x5A38, i & 0xFF, index + ((i & 0xFFFF) * 8));
      i += 1;
    }
    while (((u32) (i & 0xFFFF)) < 0x40U);
    func_80084B50();
    flags = result;
    if (crc32_compute(index + 4, 0x1FC) != (*((s32 *) (stream_state + 0x6E22))))
    {
      flags = result;
      needRecovery = stream_header_is_valid();
      if (needRecovery != 0)
      {
        func_8006F628();
        ;
      }
    }
    return result;
  }
}
