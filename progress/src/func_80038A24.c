s32 heapFreeBlock();
s32 voicesSetParamsByKey();

/* Tears down the six 12-byte entries of the block at obj->+0x68 (each closed via
 * voicesSetParamsByKey with flag 0), then frees the block. */
void func_80038A24(void *obj)
{
  s32 block;
  u8 index;

  block = *((s32 *) *((s32 *) ((char *) obj + 0x68)));
  index = 0;
  do
  {
    voicesSetParamsByKey(block + index * 12, 0);
    index++;
  }
  while (index < 6);
  heapFreeBlock(block);
}
