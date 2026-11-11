extern int gRecords;
s32 select_load_texture_pack();
s32 league_set_flag14();
extern void *gSelectState;
extern char gStreamState[];
static inline void *inline_fn(char *arg0, int arg1)
{
  return *((void **) (arg0 + arg1));
}

/* Resets the select-state flag at 0x245, hands the stream group at 0x325A to
 * league_set_flag14, and when the record's value at 0x4E changed, stores it and
 * refreshes the record. Returns the sum of the group's and select state's
 * offsets (0xD and 0x238). */
s32 func_8007B0B8(void)
{
  u16 recValue;
  void *rec;
  void *state;
  *((s8 *) (((char *) gSelectState) + 0x245)) = 0;
  league_set_flag14(inline_fn(gStreamState, 0x325A));
  state = gSelectState;
  rec = gRecords + ((*((u8 *) (((char *) (gRecords + (*((s8 *) (((char *) state) + 0x228))))) + 0x32))) * 0x28);
  recValue = *((u16 *) (((char *) rec) + 0x4E));
  if ((*((u8 *) (((char *) state) + 0x237))) != recValue)
  {
    *((u8 *) (((char *) state) + 0x237)) = (u8) recValue;
    select_load_texture_pack(rec, state);
    *((s8 *) (((char *) gSelectState) + 0x2BD)) = 1;
  }
  return (*((u8 *) (((char *) (((*((s16 *) (((char *) inline_fn(gStreamState, 0x325A)) + 2))) * 0x14) + (*((s32 *) (((char *) inline_fn(gStreamState, 0x325A)) + 0x10))))) + 0xD))) + (*((u8 *) (((char *) gSelectState) + 0x238)));
}
