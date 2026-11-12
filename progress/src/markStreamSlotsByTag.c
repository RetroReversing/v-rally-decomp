extern char stream_state[];
#define gStreamGroups (*(char **)(stream_state + 0x10386))
#define gStreamGroupCount (*(u16 *)(stream_state + 0x10370))
static inline int groupIdxInRange(s32 groupIdx)
{
  return ((u32) (groupIdx & 0xFF)) < ((u16) gStreamGroupCount);
}

static inline int slotInGroup(s32 slot, char *group)
{
  return ((u32) (slot & 0xFF)) < ((u16) (*((u16 *) (group + 0x14))));
}

/* Walks the stream groups (0x2C4 bytes each, slot count at +0x14) and, in the first group
 * that has a slot whose tag byte at +0x37 equals `tag`, sets that slot's bit in the group
 * mask table at stream_state+0x327E. Stops after the first match. */
void markStreamSlotsByTag(s32 tag)
{
  s32 slot;
  s32 slotIdx;
  s32 zero;
  u32 groupIdx;
  u16 found;
  s32 group;
  char *groupBase;
  char *groupPtr;

  found = 1;
  groupBase = gStreamGroups;
  group = 0;
  groupPtr = (char *)groupBase + 0x14;
  if (gStreamGroupCount != 0)
  {
    zero = 0;
    do
    {
      slot = 0;
      if ((((u32) zero) < ((u16) (*((u16 *) (groupBase + 0x14))))) && found)
      {
        groupIdx = group & 0xFF;
        do
        {
          slotIdx = slot & 0xFF;
          if ((*((u8 *) (((char *) (groupBase + (slotIdx << 6))) + 0x37))) == (tag & 0xFFFF))
          {
            found = 0;
            *((stream_state + 0x327E) + groupIdx) = (*((stream_state + 0x327E) + groupIdx)) | (1 << slotIdx);
          }
          slot += 1;
        }
        while (found & slotInGroup(slot, groupBase));
      }
      groupPtr += 0x2C4;
      groupBase += 0x2C4;
      group += 1;
    }
    while (found & groupIdxInRange(group));
  }
}