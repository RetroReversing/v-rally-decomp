typedef struct 
{
  s32 w[5];
} IOArgs;
extern s32 dmaCopyChunks(s32, u8 *, s32, s32, IOArgs);
extern s32 order_sync_stream_pos(u8 *);
extern u8 gOrderState[];
extern u8 stream_state[];

/* Returns the next byte of the sample stream. Refills the 0x2000-byte read buffer by DMA when it runs dry,
 * and returns -1 once the stream's chunk budget is used up. */
s32 order_stream_next_byte(void)
{
  u8 *new_var;
  s32 new_var2;
  s32 bytesLeft;
  u8 *readPtr;

  if ((*((s32 *) (gOrderState + 0x8ACC))) <= 0)
  {
    --(*((s32 *) (gOrderState + 0x8ACC)));
    *((s32 *) (stream_state + 0x3092)) = 0;
    return -1;
  }
  bytesLeft = *((s32 *) (stream_state + 0x3092));
  if (bytesLeft <= 0)
  {
    new_var2 = *((s32 *) (gOrderState + 0x2358));
    dmaCopyChunks(((*((s32 *) (gOrderState + 0x8AB0))) + (*((s32 *) (stream_state + 0x30A6)))) + 0x2000, *((u8 **) (stream_state + 0x308A)), 0x2000, new_var2, *((IOArgs *) (gOrderState + 0x235C)));
    *((s32 *) (stream_state + 0x3092)) = 0x2000;
    *((s32 *) (stream_state + 0x30A6)) += 0x2000;
    *((u8 **) (stream_state + 0x308E)) = *((u8 **) (stream_state + 0x308A));
    new_var = stream_state;
    order_sync_stream_pos(*((u8 **) (new_var + 0x308A)));
    ;
  }
  readPtr = *((u8 **) (stream_state + 0x308E));
  *((s32 *) (stream_state + 0x3092)) = (*((s32 *) (stream_state + 0x3092))) - 1;
  *((u8 **) (stream_state + 0x308E)) = readPtr + 1;
  return *readPtr;
}
