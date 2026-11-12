void streamFreeObject(s32);
void heapFreeBlock(s32);
extern char gOrderState[];

/* Frees a stream table: the object behind each entry, the entry array, and the
 * table's own block. Also clears the counter at gOrderState + 0x82AC. */
void stream_free_table(char *table)
{
  char pad[8];
  char *base;
  s32 count;
  s32 i;
  char *slot;

  base = table;
  count = *(u16 *)(*(char **)(base + 8) + 0x30);
  *(s32 *)(gOrderState + 0x82AC) = 0;
  i = 0;
  if (count != 0) {
    do {
#ifdef PORT
      streamFreeObject(*(s32 *)(*(char **)(*(char **)(base + 0x10) + i * 4) + 0x90));
      i++;
      heapFreeBlock(*(s32 *)(*(char **)(base + 0x10) + (i - 1) * 4));
#else
      slot = (char *)(i * 4);
      streamFreeObject(*(s32 *)(*(s32 *)((s32)slot + *(s32 *)(base + 0x10)) + 0x90));
      i++;
      slot = slot + *(s32 *)(base + 0x10);
      heapFreeBlock(*(s32 *)slot);
#endif
    } while (i < count);
  }
  heapFreeBlock(*(s32 *)(base + 0x10));
  heapFreeBlock(*(s32 *)(*(char **)(base + 8) + 0x24));
}
