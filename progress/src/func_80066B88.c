typedef struct
{
  u8 x[4];
} Four;
extern Four D_800A56F0;
extern u8 *gRecords;
void glyph_record_pack(u8);
void glyph_record_reset(u8);
s32 save_race_to_pak(void);

/* Walks the two-place record order against the saved table. Slots whose name
 * is still blank are free; if the place being filled is free, the new record
 * is written into it, otherwise the two places are swapped. */
void func_80066B88(void)
{
  u8 in_order[4];
  u8 free_slot[4];
  u8 changed;
  s8 pass;
  s8 slot;
  s8 m;
  s8 found;
  s8 *order;
  u8 *entry_names;
  s8 tmp;
  s8 k;

  *((Four *) in_order) = D_800A56F0;
  *((Four *) free_slot) = D_800A56F0;
  changed = 0;
  entry_names = gRecords + 0x44;
  order = (s8 *) gRecords + 0x32;
  for (pass = 0; pass < 2; pass++)
  {
    for (slot = 0; slot < 4; slot++)
    {
      if (entry_names[slot * 40] < 0x5B)
      {
        free_slot[slot] = 0;
      }
      for (m = 0; m < 2; m++)
      {
        if (order[m] == slot)
        {
          in_order[order[m]] = 0;
        }
      }
    }
    if (free_slot[order[pass]])
    {
      for (slot = 0; slot < 4; slot++)
      {
        if (in_order[slot] && !free_slot[slot])
        {
          break;
        }
      }
      if (slot == 4)
      {
        s8 *place = &order[pass];
        glyph_record_reset(*place);
        entry_names[*place * 40] = 0x50;
        entry_names[*place * 40 + 1] = 0x4C;
        entry_names[*place * 40 + 2] = *place + 0x41;
        glyph_record_pack(*place);
        changed = 1;
      }
      else
      {
        found = slot;
        for (slot = 0; slot < 4 && order[slot] != found; slot++)
        {
        }
        tmp = order[pass];
        order[pass] = found;
        order[slot] = tmp;
      }
    }
  }
  if (changed)
  {
    save_race_to_pak();
  }
}
