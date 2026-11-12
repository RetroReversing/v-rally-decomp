/* Largest free block size in a heap. If the block at ptr-9 is flagged, walks the free list
 * starting at the header and returns the biggest free payload; otherwise returns the room
 * left in the block itself, after its 0x34-byte overhead. */
u32 heapMaxFreeSize(u8 *ptr)
{
  int end;
  u32 max;
  u32 size;
  u8 *cur;
  u8 *node;
  node = ptr;
  ptr = ptr - 0x14;
  if (node[-9] != 0)
  {
    cur = ptr + 0x14;
    max = 0;
    if (cur != NULL)
    {
      do
      {
        if (cur[0xA] == 0)
        {
#ifdef PORT
          size = *(u8 **) cur - 0x14 - cur;
#else
          end = (*((u32 *) cur)) - 0x14;
          size = end - ((u32) cur);
#endif
          if (max < size)
          {
            max = size;
          }
        }
        cur = *((u8 **) cur);
      }
      while (cur != NULL);
    }
  }
  else
  {
#ifdef PORT
    max = (*(u8 **) (node - 0x14) - ptr) - 0x34;
#else
    max = ((*((u32 *) (node - 0x14))) - ((u32) ptr)) - 0x34;
#endif
  }
  return max;
}
