extern unsigned short gTexPackCount;
s32 streamReleaseEntry();
extern s32 gSelectState;

/* Releases the stream block held by each texture pack slot and clears the slot. */
void tex_packs_release(void)
{
  s32 slot_off;
  s32 block;
  s32 i;

  i = 0;
  if (gTexPackCount != 0)
  {
    do
    {
      slot_off = (i & 0xFF) * 4;
      block = *((s32 *) (((char *) (slot_off + gSelectState)) + 0x194));
      if ((*((s32 *) (((char *) (((i & 0xFF) * 4) + gSelectState)) + 0x194))) != 0)
      {
        streamReleaseEntry(block);
      }
      *((s32 *) (((char *) (((i & 0xFF) * 4) + gSelectState)) + 0x194)) = 0;
      i += 1;
    }
    while (((u32) (i & 0xFF)) < ((u16) gTexPackCount));
  }
}
