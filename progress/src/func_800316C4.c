extern void func_8002FFA4(void *, s32, s16, void *);

/* Spreads a level ramp from the table's start byte to its end byte across the entries, one step per entry. */
void func_800316C4(void *obj)
{
  s32 index;
  s32 entryOffset;
  s32 step;
  s32 index2;
  char *entryBase;
  u8 startByte;
  u8 endByte;
  s32 value;
  s32 level;
  void *table;

  table = *((void **) (((char *) obj) + 0x78));
  index = *((u16 *) (((char *) obj) + 0x88));
  startByte = *((u8 *) (((char *) table) + 0x14));
  endByte = *((u8 *) (((char *) table) + 0x17));
  step = ((s32) (endByte - startByte)) / ((s32) (index - 1));
  level = startByte;
  value = level;
  index2 = 0;
  if (index == 0)
  {
    goto block_3;
  }
  value = (level << 2) + level;
  loop_2:
  index = index2 & 0xFFFF;
  func_8002FFA4(obj, index, (s16) level, (void *) (((*((s32 *) (((char *) (*((void **) (((char *) obj) + 0x78)))) + 0x1C))) + (index * 0xC)) + 6));
  index2 += 1;
  entryBase = ((char *) (*((void **) (((char *) obj) + 0x78)))) + 0x1C;
  *((s16 *) (((char *) ((index * 0xC) + (*((s32 *) entryBase)))) + 4)) = (s16) (value * 2);
  value += (step << 2) + step;
  if (((u32) (index2 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) obj) + 0x88)))))
  {
    level += step;
    goto loop_2;
  }
  block_3:
  return;
}
