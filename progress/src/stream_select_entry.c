extern s32 gStreamSeekPos;
extern unsigned short gStreamHdrFlags;
s32 streamReadBytes();
s32 func_80082290();
s32 func_80084740();
extern char gOrderState[];
extern char gStreamState[];

/* Points the stream at entry `index` of the order table: the table's base offset at
   gOrderState+0x8AE0 plus index*8 goes into gStreamSeekPos. It then reads the 4-byte
   entry header from just before the table, calls func_80084740, and reads the
   header-flagged block through func_80082290. */
void stream_select_entry(s32 index)
{
  s32 *tableBase;
  s32 seekPos;
  s32 readLen;
  void *dst;

  tableBase = (s32 *)(gOrderState + 0x8AE0);
  seekPos = *tableBase;
  readLen = index * 8;
  dst = tableBase;
  dst = dst - 8;
  seekPos += readLen;
  gStreamSeekPos = seekPos;
  readLen = 4;
  streamReadBytes(dst, 4);
  func_80084740();
  dst = gStreamState + 0x30D6;
  dst = (void *) gStreamHdrFlags;
  func_80082290(dst);
}
