extern int D_800C337C;
extern int gStreamHdrDataOffset;
extern char gOrderState[];
extern char gStreamState[];
s32 stream_store_entry_fields(void)
{
  char *new_var;
  new_var = gOrderState;
  *((s32 *) (((char *) (*((void **) (new_var + 0x8AE4)))) + 4)) = (s32) D_800C337C;
  *((s32 *) (((char *) (*((void **) (gOrderState + 0x8AE4)))) + 0)) = (s32) gStreamHdrDataOffset;
  return 1;
}
