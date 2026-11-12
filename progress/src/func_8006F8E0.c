typedef struct
{
  u8 pad[0x14];
  u16 count;
  u8 rest[0x2AE];
} RecordGroup;
extern u8 stream_state[];
void build_record_entry_alt(s32, s32);
void build_record_entry(s32, s32);
void record_fill_split_times(s32);
void func_8006CF7C(s32);
void func_8006CCD0(void);
void func_8006C780(void);

/* Builds the record table at startup: for each of the 8 groups, one entry per
 * group count (alt builder), then the 4 fixed kinds (4, 5, 6 and 3 entries),
 * 12 split-time blocks, 4 follow-up blocks, and the final two passes. */
void func_8006F8E0(void)
{
  s32 grp = 0;
  s32 i;
  do
  {
    s32 g = grp & 0xff;
    i = 0;
    if ((*(RecordGroup **)(stream_state + 0x10386))[g].count != 0)
    {
      unsigned short n;
      do
      {
        build_record_entry_alt(g, i & 0xff);
        n = g;
        n = (*((RecordGroup **) (stream_state + 0x10386)))[n].count;
        i++;
      }
      while (((u32) (i & 0xff)) < ((u32) n));
    }
    grp++;
  }
  while (((u32) (grp & 0xff)) < 8);
  for (i = 0; ((u32) (i & 0xff)) < 4; i++)
  {
    build_record_entry(1, i & 0xff);
  }

  for (i = 0; ((u32) (i & 0xff)) < 5; i++)
  {
    build_record_entry(2, i & 0xff);
  }

  for (i = 0; ((u32) (i & 0xff)) < 6; i++)
  {
    build_record_entry(3, i & 0xff);
  }

  for (i = 0; ((u32) (i & 0xff)) < 3; i++)
  {
    build_record_entry(4, i & 0xff);
  }

  for (grp = 0; ((u32) (grp & 0xff)) < 12; grp++)
  {
    record_fill_split_times(grp & 0xff);
  }

  for (grp = 0; ((u32) (grp & 0xff)) < 4; grp++)
  {
    func_8006CF7C(grp & 0xff);
  }

  func_8006CCD0();
  func_8006C780();
}
