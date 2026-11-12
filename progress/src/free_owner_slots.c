s32 heapFreeBlock();
extern char stream_state[];

/* Frees the blocks of the active slots of an owner. The slot count is the byte at +0x111
 * of the owner, or 4 when the stream state's mode (u16 at +0x1E) is set. Each 0x44-byte
 * slot whose in-use flag (bit 0 at +8) is set frees its two blocks (+0 and +4) and
 * clears the flag. */
void free_owner_slots(void *owner)
{
  u8 i;
  u8 count;
  s32 n;
  void *slot;
  void *obj;

  obj = owner;
  if (*(u16 *)((char *)*(void **)(stream_state + 0x32F2) + 0x1E) == 0) {
    n = *(u8 *)((char *)obj + 0x111);
  } else {
    n = 4;
  }
  n &= 0xFF;
  if (n != 0) {
    i = 0;
    count = n;
    do {
      slot = (char *)obj + (i * 0x44);
      if (*(u16 *)((char *)slot + 8) & 1) {
        if (*(s32 *)slot != 0) {
          heapFreeBlock(*(s32 *)slot);
        }
        if (*(s32 *)((char *)slot + 4) != 0) {
          heapFreeBlock(*(s32 *)((char *)slot + 4));
        }
        *(u16 *)((char *)slot + 8) = 0;
      }
      i++;
    } while (i < count);
  }
}
