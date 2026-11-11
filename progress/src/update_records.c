extern u8 gStreamState[];
extern u8 gOrderState[];
extern s32 gRecordTimeScale;
void func_800535F4(void *);
void copyStringAligned(void *, void *);
extern u8 *gRecords;

/* Refreshes each record in gRecords (the count is the u16 at +14): copies its table slot,
 * scales its timer by gRecordTimeScale, and updates its flag bits and per-entry values. */
void update_records(void)
{
  char *rec_addr;
  u8 *hdr;
  u8 *tab;
  u8 *tab2;
  u8 *slot;
  u8 *entry;
  u32 val;
  s32 i;
  s32 n;
  s32 off;
  u16 mode;
  s32 idx;
  u8 ent_index;

  hdr = gRecords;
  i = 0;
  if (*((u16 *) (hdr + 14)))
  {
    tab = gOrderState + 0x6dac;
    tab2 = tab + 16;
    do
    {
      mode = *((u16 *) (hdr + 30));
      n = i & 255;
      off = n << 5;
      slot = (gStreamState + 0x3392) + (mode << 6);
      *((s32 *) slot) = *((s32 *) ((tab + (mode * 4)) + off));
      entry = hdr + n;
      ent_index = entry[0x32];
      rec_addr = (char *) ((hdr + (ent_index * 40)) + 78);
      slot[4] = *((u16 *) rec_addr);
      slot[5] = *((u16 *) (gRecords + 22));
      copyStringAligned(slot + 6, gRecords + ((*(gRecords + n + 50) * 40) + 68));
      {
      u8 *g = gRecords;
 do { *(u32 *) ((((*((u16 *) (g + 30))) * 4) + tab2) + off) /= 100; val = *((u32 *) ((((*((u16 *) (g + 30))) * 4) + tab2) + off)); val = ((s32) val) * gRecordTimeScale; idx = *((s32 *) slot); slot[10] = ((u32) (val * 3600)) / ((u32) (5 * (idx * 2))); } while (0);
      }
      *(u32 *) ((((*((u16 *) (gRecords + 30))) * 4) + tab2) + off) *= 100;
      slot[11] = 0;
      slot[12] = 1;
      if ((*((u16 *) (gRecords + 44))) & 0x4000)
      {
        s32 prev_off;
        u32 prev_val;
        prev_off = ((*((u16 *) (gRecords + 30))) - 1) << 6;
        if (*((u8 *) ((gStreamState + 0x33ae) + prev_off)))
        {
          prev_val = *((u32 *) ((gStreamState + 0x33a2) + prev_off));
          if (prev_val >= 11)
          {
            *((s32 *) slot) = prev_val - 3;
          }
        }
        else
        {
          prev_val = *((u32 *) ((gStreamState + 0x33a2) + prev_off));
          if (prev_val >= 31)
          {
            *((s32 *) slot) = prev_val - 10;
          }
        }
      }
      func_800535F4((gStreamState + 0x3362) + ((*((u16 *) (gRecords + 30))) << 6));
      hdr = gRecords;
      i++;
    }
    while (((u32) (i & 255)) < (*((u16 *) (hdr + 14))));
  }
}
