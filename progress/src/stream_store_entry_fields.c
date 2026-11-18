/* Writes the stream header's data offset and seek position into the order state's stream header block. */ extern int D_800C337C;
extern int gStreamHdrDataOffset;
extern char gOrderState[];
extern char stream_state[];
/* Writes the stream seek position and header data offset into the stream header block that the order state points to at +0x8AE4. */ s32 stream_store_entry_fields(void)
{
  char *order_state;
  order_state = gOrderState;
  *((s32 *) (((char *) (*((void **) (order_state + 0x8AE4)))) + 4)) = (s32) D_800C337C;
  *((s32 *) (((char *) (*((void **) (gOrderState + 0x8AE4)))) + 0)) = (s32) gStreamHdrDataOffset;
  return 1;
}
