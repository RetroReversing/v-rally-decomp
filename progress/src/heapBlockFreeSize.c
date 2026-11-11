/* Returns the free bytes available in the heap block whose payload starts at block.
 * Each block has a 0x14-byte header. Its first word links to the next block's payload.
 * When the flag at block[-9] is set, the free size is summed over the chain of free blocks
 * (those with a zero byte at +0xA) starting at block. Otherwise it is the gap to the next
 * block, less the 0x34 bytes of overhead. */
s32 heapBlockFreeSize(u8 *block)
{
  u8 *payload;
  s32 total;

  payload = block;
  block = block - 0x14;
  if (payload[-9] != 0) {
    block = block + 0x14;
    total = 0;
    if (block != NULL) {
      do {
        if (block[0xA] == 0) {
          total += *(s32 *)block - (0x14 + (s32)block);
        }
        block = *(u8 **)block;
      } while (block != NULL);
    }
  } else {
    total = (*(s32 *)(payload - 0x14) - (s32)block) - 0x34;
  }
  return total;
}
