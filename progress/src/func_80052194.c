extern char D_800A5008[];
extern char gOrderState[];
s32 order_table_swap();

/* Walks the first `count` entries of the 0x14-byte table at gOrderState+0x237C. Each entry whose first
 * byte equals D_800A5008's address has its order slots swapped by order_table_swap, numbered from 0. */
void func_80052194(s32 count)
{
  char pad[8];
  s32 *entry_ptr;
  char (*base)[];
  s32 idx;
  s32 match_no;
  s32 entry_idx;
  s32 offset;
  s32 matches;
  s32 limit;
  u8 *entry;
  limit = count;
  matches = 0;
  entry_idx = 0;
  if (limit > 0)
  {
    base = &D_800A5008;
    entry_ptr = (s32 *)base;
    offset = 0;
    do
    {
      #ifdef PORT
      entry = *(u8 **)(gOrderState + 0x237C) + offset;
#else
      entry = (u8 *)(offset + *(u32 *)(gOrderState + 0x237C));
#endif
      #ifdef PORT
      if (*entry == (unsigned long)base)
#else
      if (*entry == (s32)base)
#endif
      {
        match_no = matches & 0xFFFF;
        matches += 1;
        idx = entry_idx & 0xFFFF;
        order_table_swap(idx, match_no);
      }
      entry_idx += 1;
      offset += 0x14;
    }
    while (entry_idx < limit);
  }
}
