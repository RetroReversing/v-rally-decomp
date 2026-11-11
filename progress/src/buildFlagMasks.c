typedef struct
{
  u8 flag[32];
} FlagBlock;

typedef struct
{
  u8 pad[0x14];
  u16 count;
  u8 pad2[0x2AE];
} SlotTableEntry;

extern FlagBlock gFlagBlock;
extern u8 gMaskSlot[];
extern u8 gFlagMasks[];
extern SlotTableEntry *gSlotTableB;
extern SlotTableEntry *D_800D0648;

/* Clears the 8 direct flag masks, then walks 12 groups of flags (group g has
 * D_800D0648[g].count entries, numbered across groups by flagIdx). A set flag
 * in group g < 8 sets bit `bit` of gFlagMasks[g]; for g >= 8 it sets bit
 * (gSlotTableB[slot].count + bit - 2) of gFlagMasks[slot], where slot = gMaskSlot[g]. */
void buildFlagMasks(void)
{
  FlagBlock flags;
  u32 flagIdx;
  u8 group;
  u8 bit;

  flags = gFlagBlock;
  flagIdx = 0;
  for (group = 0; group < 8; group++)
  {
    gFlagMasks[group] = 0;
  }

  group = 0;
  bit = 0;
  do
  {
    for (bit = 0; bit < D_800D0648[group].count; bit++)
    {
      if (flags.flag[(u8) flagIdx])
      {
        if (group < 8)
        {
          gFlagMasks[group] |= 1 << bit;
        }
        else
        {
          u8 slot = gMaskSlot[group];
          s32 count = gSlotTableB[slot].count;
          s32 shift = bit - 2;
          gFlagMasks[slot] |= 1 << (count + shift);
        }
      }
      flagIdx++;
    }

    group++;
  }
  while (group < 12);
}
