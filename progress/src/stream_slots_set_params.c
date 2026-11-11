extern char gOrderState[];
extern char gStreamState[];

/* Walks the linked list of stream slots and sets each slot's fixed value (300) and its
 * per-slot value, taken from the negated field at +0xDC of obj, plus bonuses from the
 * current config's type field. */
void stream_slots_set_params(void *obj)
{
  u8 slot_count;
  char *cfg;
  char *cfg_copy;
  char *slot;
  s32 base_value;
  u32 i;
  cfg = *((char **) (gStreamState + 0x32F2));
  slot_count = *((u8 *) (cfg + 0xF));
  slot = *((char **) (*((char **) (gOrderState + 0x6D94))));
  i = 1;
  if (slot_count != 0)
  {
    do
    {
      *((s32 *) (slot + 0x14)) = 0x12C;
      base_value = -(*((s32 *) (((char *) obj) + 0xDC)));
      *((s32 *) (slot + 0x18)) = base_value;
      cfg_copy = cfg;
      if ((*((u16 *) (cfg_copy + 0xE))) == 2)
      {
        if ((*((u16 *) (cfg_copy + 0x12))) & 1)
        {
          *((s32 *) (slot + 0x18)) = base_value + 0x28;
        }
      }
      if (!((*((u16 *) (cfg_copy + 0xE))) < 3))
      {
        *((s32 *) (slot + 0x18)) += 0x64;
      }
      slot = *((char **) (slot + 4));
      i++;
    }
    while (slot_count >= i);
  }
}
