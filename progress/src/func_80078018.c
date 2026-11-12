typedef struct RaceNode
{
  u32 pad;
  struct RaceNode *next;
  u8 data[64];
  s32 *type;
} RaceNode;
typedef struct
{
  char name[4];
  u32 time;
  s32 diff;
  u32 speed;
  u8 type;
  u8 idx;
  u8 car;
  u8 pad;
  RaceNode *node;
} ResultEntry;
typedef struct
{
  char name[10];
  u16 car;
  u8 pad[28];
} DriverInfo;
typedef struct
{
  u8 pad0[0x1E];
  u16 track;
  u8 pad20[0x12];
  u8 slot[0x12];
  DriverInfo drivers[8];
} RaceRecords;
typedef struct
{
  u32 lap[4];
  u32 dist[4];
} Rec;
extern RaceNode **gCarList;
extern RaceRecords *gRecords;
extern ResultEntry gResultsTable[5];
extern u8 D_800C3616[];
extern u8 D_800C3654[];
extern u8 D_800C365A[];
extern u8 D_800C8002;
extern s32 D_800C7FF4;
extern s32 D_800C7FFC;
extern u8 D_800C3650[];
extern char D_800C7FF0[];
extern Rec D_800B55FC[];
extern s32 gRecordTimeScale;
extern void memset(void *, s32, s32);
extern void strCpy(void *, void *);
extern u8 func_80077FA8(u8);

/* Builds the race results table from the finishing order in the node list:
 * each driver's time, speed and car, with the gap to the leader. Then copies the
 * track name and loads the per-track constants. */
void func_80078018(void)
{
  u8 i = 0;
  RaceNode *node = *gCarList;
  u8 k;
  s32 n;
  s32 carId;

  memset(gResultsTable, 0, 120);
  while (node)
  {
    k = func_80077FA8(i);
    if (gResultsTable[k].node)
      k--;
    gResultsTable[k].node = node;
    strCpy(gResultsTable[k].name, gRecords->drivers[gRecords->slot[i]].name);
    carId = gRecords->drivers[gRecords->slot[i]].car;
    gResultsTable[k].idx = i;
    gResultsTable[k].car = carId;
    {
    u32 *lap = D_800B55FC->lap;
    u32 *dist = D_800B55FC->dist;
    RaceRecords *records = gRecords;
#ifdef PORT
#define TRACK_VAL(b) (*(u32 *)((u8 *)(b) + records->track * 4 + (s32)(i << 5)))
#else
#define TRACK_VAL(b) (*(u32 *)((u32)(b) + records->track * 4 + (s32)(i << 5)))
#endif
    gResultsTable[k].time = TRACK_VAL(lap);
    TRACK_VAL(dist) /= 100;
    gResultsTable[k].speed = (TRACK_VAL(dist) * gRecordTimeScale * 3600) / (TRACK_VAL(lap) * 10);
    }
    gResultsTable[k].type = *node->type;
    node = node->next;
    i++;
  }
  for (n = 0; (u8)n < 4; n++)
  {
    if (gResultsTable[(u8)n].time)
    {
      s32 gap = gResultsTable[(u8)n].time - gResultsTable[0].time;
      gResultsTable[(u8)n].diff = __builtin_abs(gap); }
    else
    {
      gResultsTable[(u8)n].diff = 0;
    }
  }
  strCpy(D_800C7FF0, D_800C3616 + gRecords->track * 64);
  {
  u8 *raw = (u8 *)gRecords;
  D_800C7FF4 = *(s32 *)(D_800C3650 + ((*(u16 *)(raw + 0x1E) - 1) << 6));
  D_800C7FFC = D_800C365A[(*(u16 *)(raw + 0x1E) - 1) << 6];
  D_800C8002 = D_800C3654[(*(u16 *)(raw + 0x1E) - 1) << 6];
  }
}
