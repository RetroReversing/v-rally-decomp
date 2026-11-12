extern u8 D_8009BBBC;
extern char stream_state[];
void *poolAllocNode(s32 a0, s32 a1);

/* Allocates one 0x24-byte slot record for each stream slot the base table asks for (base[0xF], or 1 when D_8009BBBC is set) and resets its fields. */
void stream_alloc_slots(s32 channel)
{
  u32 v;
  u32 count;
  u32 i;
  u8 *base;
  u8 *slot;

  base = *((u8 **) (stream_state + 0x32F2));
  if (D_8009BBBC == 0)
  {
    v = base[0xF];
  }
  else
  {
    v = 1;
  }
  v &= 0xFF;
  if (v != 0)
  {
    count = v;
    i = 1;
    do
    {
      slot = poolAllocNode(channel, 0x24);
      *((s32 *) (slot + 0x14)) = 0;
      *((s16 *) (slot + 0x18)) = 1;
      *((s16 *) (slot + 0x1C)) = (v = 0);
      *((s16 *) (slot + 0x1A)) = 0;
      *((s16 *) (slot + 0x1E)) = -1;
      *((s16 *) (0x20 + slot)) = -1;
      i++;
    }
    while (((unsigned short) count) >= i);
  }
}
