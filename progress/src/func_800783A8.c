#define GAME_STATE gRecords
#define RESULTS gResultsTable
#define TRACK_TABLE g_split_times
#define RECORD_TABLE gSlotTableB
#define STATS_TABLE (&gDecodeBlk)
typedef struct 
{
  u32 score;
  u8 b4;
  u8 b5;
  char name[4];
  u8 laps;
  u8 bB;
  u8 flag;
  u8 pad[3];
} Item;
typedef struct 
{
  Item item[4];
} Track;
typedef struct 
{
  char name[4];
  s32 time;
  s32 diff;
  u32 avg;
  u8 b10;
  u8 idx;
  u8 b12;
  u8 pad;
  void *ptr;
} Ent;
typedef struct 
{
  u8 pad[0x22C];
  s32 v[3];
  u8 pad2[0x2C4 - 0x238];
} Rec;
typedef struct Node
{
  u8 pad[4];
  struct Node *next;
  u8 pad8[0x48 - 8];
  s32 *p48;
} Node;
typedef struct 
{
  u8 pad[0x58];
  s32 best[12][4];
  s32 a[4];
  s32 b[4];
  s32 c[4];
} Stats;
extern char gOrderState[];
extern char gStreamState[];
extern s32 gRecordTimeScale;
extern u8 *gRecords;
extern Ent gResultsTable[5];
extern Track g_split_times[];
extern Rec *gSlotTableB[];
extern Stats gDecodeBlk;
extern Node **gCarList;
void memset(void *, s32, s32);
u8 func_80078338(u8);
void copyStringAligned(char *, void *);

/* Builds the results table (RESULTS) for the finished race: one entry per
 * node of the result list, with the best time and average speed for the
 * current track and car, then the time differences to the leader, and the
 * track's own record in entry 4. */
void func_800783A8(void)
{
  char *entryPtr;
  u8 nodeIdx;
  Node *node;
  Stats *st;
  Rec **recs;
  u8 slot;
  s32 sum;
  s32 cnt;
  Rec *rec;
  u8 i;
  s32 delta;
  nodeIdx = 0;
  node = *(*((Node ***) (gOrderState + 0x73F0)));
  st = STATS_TABLE;
  memset(RESULTS, 0, 0x78);
  i = 0;
  if (node != 0)
  {
    recs = RECORD_TABLE;
    do
    {
      slot = func_80078338(nodeIdx);
      if (RESULTS[slot].ptr != 0)
      {
        slot--;
      }
      RESULTS[slot].ptr = node;
      copyStringAligned(RESULTS[slot].name, GAME_STATE + (((GAME_STATE + nodeIdx)[0x32] * 40) + 0x44));
      entryPtr = (char *) ((GAME_STATE + ((GAME_STATE + nodeIdx)[0x32] * 40)) + 0x4E);
      RESULTS[slot].b12 = *((u16 *) entryPtr);
      RESULTS[slot].idx = nodeIdx;
      RESULTS[slot].time = st->best[*((u16 *) (GAME_STATE + 0x20))][nodeIdx];
      sum = 0;
      cnt = 0;
      rec = recs[*((u16 *) (GAME_STATE + 0x1E))] + (*((u16 *) (GAME_STATE + 0x20)));
      if (st->a[nodeIdx] != 0)
      {
        sum = rec->v[0];
        cnt = st->a[nodeIdx];
      }
      if (st->b[nodeIdx] != 0)
      {
        cnt += st->b[nodeIdx];
        sum += rec->v[1];
      }
      if (st->c[nodeIdx] != 0)
      {
        cnt += st->c[nodeIdx];
        sum += rec->v[2];
      }
      RESULTS[slot].avg = ((u32) ((sum * gRecordTimeScale) * 3600)) / ((u32) (cnt * 1000));
      RESULTS[slot].b10 = *node->p48;
      node = node->next;
      nodeIdx++;
    }
    while (node != 0);
    i = 0;
  }
  for (i = 0; i < 4; i++)
  {
    if (RESULTS[i].time != 0)
    {
      delta = RESULTS[i].time - RESULTS[0].time;
      RESULTS[i].diff = (delta >= 0) ? delta : -delta; } else { RESULTS[i].diff = 0;
    }
  }
  copyStringAligned(RESULTS[4].name, TRACK_TABLE[*((u16 *) (GAME_STATE + 0x20))].item[0].name);
  RESULTS[4].time = TRACK_TABLE[*((u16 *) (GAME_STATE + 0x20))].item[0].score;
  RESULTS[4].avg = TRACK_TABLE[*((u16 *) (GAME_STATE + 0x20))].item[0].laps;
  RESULTS[4].b12 = TRACK_TABLE[*((u16 *) (GAME_STATE + 0x20))].item[0].b4;
  if (RESULTS[0].b10 < 4)
  {
    *((u16 *) (GAME_STATE + 0x2A)) |= 1 << (*((u16 *) (GAME_STATE + 0x20)));
  }
}
