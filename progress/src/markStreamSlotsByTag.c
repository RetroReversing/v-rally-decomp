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
  s32 slot_no;
  s32 slot_no_byte;
  s32 zero;
  u32 group_no_byte;
  u16 searching;
  s32 group_no;
  char *group_base;
  char *group_ptr;

  searching = 1;
  group_base = gStreamGroups;
  group_no = 0;
  group_ptr = (char *)group_base + 0x14;
  if (gStreamGroupCount != 0)
  {
    zero = 0;
    do
    {
      slot_no = 0;
      if ((((u32) zero) < ((u16) (*((u16 *) (group_base + 0x14))))) && searching)
      {
        group_no_byte = group_no & 0xFF;
        do
        {
          slot_no_byte = slot_no & 0xFF;
          if ((*((u8 *) (((char *) (group_base + (slot_no_byte << 6))) + 0x37))) == (tag & 0xFFFF))
          {
            searching = 0;
            *((stream_state + 0x327E) + group_no_byte) = (*((stream_state + 0x327E) + group_no_byte)) | (1 << slot_no_byte);
          }
          slot_no += 1;
        }
        while (searching & slotInGroup(slot_no, group_base));
      }
      group_ptr += 0x2C4;
      group_base += 0x2C4;
      group_no += 1;
    }
    while (searching & groupIdxInRange(group_no));
  }
}
