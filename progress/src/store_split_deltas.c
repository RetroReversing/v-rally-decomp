typedef struct Item
{
  s32 x;
  u8 pad[0xC];
} Item;
typedef struct Group
{
  Item item[4];
} Group;
typedef struct Game
{
  u8 pad00[0x20];
  u16 sel;
} Game;
typedef struct Tbl
{
  u8 pad[0x15A];
  u16 v;
} Tbl;
extern Game *gRecords;
extern Group g_split_times[];
extern s32 gSplitBaseTimes[];
extern u8 gSplitRecordIds[];
extern u8 func_8006B924(Item *);

/* For the selected record, computes the three split results against the base
   times and stores them as 16-bit words in gSplitRecordIds: the value is the
   time delta (sign in bit 0), capped at 0x3FFE, with the split result in bits 14-15.
   A split with result 5 is stored as 0xFFFF. */
void store_split_deltas(void)
{
  u8 idx;
  u8 i;
  u8 *record_ids;
  u8 r;
  u8 slot_i;
  s32 d;
  record_ids = gSplitRecordIds;
  idx = gRecords->sel;
  for (i = 0; i < 3; i++)
  {
    r = func_8006B924(&g_split_times[idx].item[i]);
    slot_i = i;
    if (r == 5)
    {
      ((Tbl *) (record_ids + (((idx * 3) + slot_i) * 2)))->v = 0xFFFF;
    }
    else
    {
      d = gSplitBaseTimes[idx] - g_split_times[idx].item[slot_i].x;
      if (d >= 0)
      {
        if (d >= 0x4000)
        {
          d = 0x3FFE;
        }
        d &= ~1;
      }
      else
      {
        d = -d;
        if (d >= 0x4000)
        {
          d = 0x3FFE;
        }
        d |= 1;
      }
      ((Tbl *) (record_ids + (((idx * 3) + i) * 2)))->v = d | (r << 14);
    }
  }

}
