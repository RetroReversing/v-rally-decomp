extern char gOrderState[];
extern char *D_800C3518;
extern char D_15DB10[];
extern char D_BB9470[];
extern s32 D_8009CE70;
extern s32 D_8009CE74;
extern s32 D_8009D4E8;
extern s32 rebase_base_addr;

/* Takes a snapshot of the list: for each 0x3C-byte entry, sets flag bit 2 while the
   entry is processed, then restores the original flags. Then records the frame
   statistics from the current frame header and runs the per-frame update and
   sound/cleanup calls. */
void func_8001AE40(char *list)
{
  s32 pad[2];
  char *entry;
  s32 index;
  s32 *flags;
  s32 saved_flags;
  s32 frame_time;
  s32 count;
  entry = *((char **) list);
  index = 0;
  count = *((u16 *) (list + 4));
  if (count > 0)
  {
    flags = (s32 *) (entry + 0x10);
    do
    {
      saved_flags = *flags;
      if (saved_flags & 1)
      {
        *flags = saved_flags | 2;
      }
      func_8001AAB4((s32) entry);
      *flags = saved_flags;
      flags = (s32 *) (((char *) flags) + 0x3C);
      index += 1;
      entry += 0x3C;
    }
    while (index < (*((u16 *) (list + 4))));
  }
  frame_time = *((u16 *) ((*((char **) (gOrderState + 0x72F4))) + 0x7A));
  D_8009CE70 = ((*((s32 *) ((*((char **) (gOrderState + 0x72F4))) + 0x14))) - (*((s32 *) ((*((char **) (gOrderState + 0x72F4))) + 0x10)))) >> 3;
  D_8009CE74 = frame_time;
  func_80005D98(*((char **) (gOrderState + 0x72F4)));
  func_8004DC50(*((s32 *) (D_800C3518 + 0x24)));
  func_8004EF40(*((s32 *) (D_800C3518 + 0x24)));
  heap_free_stub(rebase_base_addr);
  heap_free_stub(D_8009D4E8);
  index = D_BB9470 - D_15DB10;
  func_80081514(D_15DB10, index, 1);
}
