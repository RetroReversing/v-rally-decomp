extern s32 gStreamSeekPos;
extern unsigned short gStreamHdrFlags;
s32 streamReadBytes();
s32 order_stream_read_block();
s32 func_80084740();
extern char gOrderState[];
extern char stream_state[];

/* Points the stream at entry `index` of the order table: the table's base offset at
   gOrderState+0x8AE0 plus index*8 goes into gStreamSeekPos. It then reads the 4-byte
   entry header from just before the table, calls func_80084740, and reads the
   header-flagged block through order_stream_read_block. */
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
  dst = stream_state + 0x30D6;
#ifdef PORT
  dst = (void *)(uintptr_t) gStreamHdrFlags;
#else
  dst = (void *) gStreamHdrFlags;
#endif
  order_stream_read_block(dst);
}