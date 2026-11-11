s32 sort_split_times(void *);
typedef struct
{
  s32 w[4];
} S_func_8006DD04_blk;

/* Takes the three 16-byte split-time records at the start of the block, saves them, marks
 * each source slot invalid (w[0] = -1), then re-inserts the saved records one at a time
 * through the slot at +0x30 and re-sorts after each insert. */
void rebuildSplitTimes(void *block)
{
  S_func_8006DD04_blk saved[3];
  u8 i;
  u32 off;
  S_func_8006DD04_blk *src;
  S_func_8006DD04_blk *dst;

  i = 0;
  do {
    off = i << 4;
    dst = (S_func_8006DD04_blk *)(off + (u32)saved);
    src = (S_func_8006DD04_blk *)(off + (u32)block);
    *dst = *src;
    src->w[0] = -1;
    i++;
  } while (i < 3);
  i = 0;
  do {
    *((S_func_8006DD04_blk *)((char *)block + 0x30)) = saved[i];
    sort_split_times(block);
    i++;
  } while (i < 3);
}
