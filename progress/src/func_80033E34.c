s32 func_8001FEDC(); void func_80030180(void *,s32,s16,s16*);

/* Works out the position of an object `progress` steps along its track path and writes
 * the x, y, z result to out_pos. The lookahead depends on the speed from func_8001FEDC. */
void func_80033E34(void *obj, s32 progress, void *out_pos)
{
  s16 sp10[3];
  void *node;
  void *cand;
  void *path;
  s32 base_idx;
  s32 lookahead;
  s32 index;
  void *next;

  path = *(void **)((u8 *)obj + 0x8c);
  node = *(void **)((u8 *)path + 0x2c);
  base_idx = *(s32 *)((u8 *)*(void **)((u8 *)obj + 0x60) + 0x2c);
  cand = (void *)func_8001FEDC();
  lookahead = (-((s32)cand >= 5000) & 5) | 4;
  if ((s32)cand < 3000) lookahead = 3;
  if ((s32)cand < 1000) lookahead = 2;
  cand = (void *)(u32)*(u16 *)((u8 *)node + 0x88);
  index = base_idx + lookahead;
  if (index < (s32)cand)
  {
    cand = node;
  }
  else
  {
    next = *(void **)((u8 *)node + 0x5c);
    if (next) node = next;
    index = (index - lookahead) - (s32)cand + lookahead + 1;
    cand = node;
  }
  func_80030180(cand, index, (s16)progress, sp10);
  *(s32 *)out_pos = sp10[0] + *(s32 *)((u8 *)node + 0x24);
  *(s32 *)((u8 *)out_pos + 4) = sp10[1] + *(s32 *)((u8 *)node + 0x28);
  *(s32 *)((u8 *)out_pos + 8) = sp10[2] + *(s32 *)((u8 *)node + 0x2c);
}
