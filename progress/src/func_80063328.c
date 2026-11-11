static inline int __repair_inline_sum(int left, int right)
{
  return left + right;
}

#define CUR_EVENT (*(RaceObj **)(gStreamState+0x32F2))
extern u8 gStreamState[];
void markStreamSlotsByTag(s32);
typedef struct 
{
  u8 pad[42];
  u16 flags;
  u32 word;
} RaceObj;

/* Rebuilds the 8-byte per-slot table at gStreamState+0x327E from the current
 * event object's flag bits, then queues the matching entries for the HUD. */
void func_80063328(void)
{
  u8 i;
  u8 level;
  s32 flags;
  s32 w;
  s32 base;
  s32 off;
  s32 bit;
  s32 base2;
  i = 0;
  do
  {
    gStreamState[0x327E + i] = 0;
    i++;
  }
  while (i < 8);
  i = 0;
  do
  {
    gStreamState[0x327E + i] |= 1;
    i++;
  }
  while (i < 8);
  flags = CUR_EVENT->flags;
  w = flags & 0x1000;
  level = w != 0;
  if (flags & 0x2000)
  {
    level++;
  }
  if (flags & 0x4000)
  {
    level++;
  }
  switch ((u8) level)
  {
    case 3:
      markStreamSlotsByTag(15);
      markStreamSlotsByTag(16);
      markStreamSlotsByTag(17);

    case 2:
      markStreamSlotsByTag(9);
      markStreamSlotsByTag(10);
      markStreamSlotsByTag(11);
      markStreamSlotsByTag(12);
      markStreamSlotsByTag(13);
      markStreamSlotsByTag(14);

    case 1:
      markStreamSlotsByTag(4);
      markStreamSlotsByTag(5);
      markStreamSlotsByTag(6);
      markStreamSlotsByTag(7);
      markStreamSlotsByTag(8);

    case 0:
      markStreamSlotsByTag(0);
      markStreamSlotsByTag(1);
      markStreamSlotsByTag(2);
      markStreamSlotsByTag(3);

  }

  base = 18;
  i = 0;
  bit = 1;
  base2 = 42;
  for (; i < 12; i++)
  {
    if ((CUR_EVENT->flags & (bit << i)) == (bit << i))
    {
      if (i < 8)
      {
        off = i * 2;
        off += i;
        off = __repair_inline_sum(base, off);
        markStreamSlotsByTag(off);
        markStreamSlotsByTag(off + 1);
        markStreamSlotsByTag(off + 2);
      }
      else
      {
        off = i - 8;
        off = off * 2;
        markStreamSlotsByTag(__repair_inline_sum(base, off + 24) & 65534);
        off = __repair_inline_sum(base2, off);
        markStreamSlotsByTag((off + 1) & 65535);
        off += 2;
        markStreamSlotsByTag(off & 65534);
      }
    }
  }

  if ((CUR_EVENT->word & 0x3000000) == 0x3000000)
  {
    i = 0;
    do
    {
      gStreamState[0x327E + i] = 255;
      i++;
    }
    while (i < 8);
  }
}
