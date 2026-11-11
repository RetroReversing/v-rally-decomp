extern u8 *D_800C7F8C;
extern void *D_800B5B44;
extern void *D_800C3518;
void func_8001A2E0(void *);
void heapFreeBlock(void *);
void streamFreeObject(void *);

/* Frees the table of 0x3C-byte entries at D_800C7F8C: for each entry with a block at +0x38, runs func_8001A2E0
 * on it and frees that block. Then frees D_800B5B44 and clears the three globals. */
void func_8001B140(void)
{
  s32 i;
  s32 count;
  u8 *p;
  u8 *info;
  s32 pad[2];

  info = D_800C7F8C;
  p = *(u8 **)info;
  count = *(u16 *)(info + 4);
  i = 0;
  if (count > 0)
  {
    do
    {
      if (*(void **)(p + 0x38) != NULL)
      {
        func_8001A2E0(p);
        heapFreeBlock(*(void **)(p + 0x38));
      }
      p += 0x3C;
      i++;
    } while (i < *(u16 *)(info + 4));
  }
  streamFreeObject(D_800B5B44);
  D_800B5B44 = NULL;
  D_800C3518 = NULL;
  D_800C7F8C = NULL;
}
