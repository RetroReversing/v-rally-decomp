#define G D_800C35A0
#define ENTS D_800C7F90
#define TRACKS D_800C3750
#define RECS D_800D0634
#define STATS (&D_800B6600)
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
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 D_8009D540;
extern u8 *D_800C35A0;
extern Ent D_800C7F90[5];
extern Track D_800C3750[];
extern Rec *D_800D0634[];
extern Stats D_800B6600;
extern Node **D_800B5C40;
void func_80097E30(void *, s32, s32);
u8 func_80078338(u8);
void func_80098290(char *, void *);
void func_800783A8(void)
{
  char *__repair_addr;
  u8 n;
  Node *node;
  Stats *st;
  Rec **recs;
  u8 slot;
  s32 sum;
  s32 cnt;
  Rec *rec;
  u8 i;
  s32 d;
  n = 0;
  node = *(*((Node ***) (D_800AE850 + 0x73F0)));
  st = STATS;
  func_80097E30(ENTS, 0, 0x78);
  i = 0;
  if (node != 0)
  {
    recs = RECS;
    do
    {
      slot = func_80078338(n);
      if (ENTS[slot].ptr != 0)
      {
        slot--;
      }
      ENTS[slot].ptr = node;
      func_80098290(ENTS[slot].name, G + (((G + n)[0x32] * 40) + 0x44));
      __repair_addr = (char *) ((G + ((G + n)[0x32] * 40)) + 0x4E);
      ENTS[slot].b12 = *((u16 *) __repair_addr);
      ENTS[slot].idx = n;
      ENTS[slot].time = st->best[*((u16 *) (G + 0x20))][n];
      sum = 0;
      cnt = 0;
      rec = recs[*((u16 *) (G + 0x1E))] + (*((u16 *) (G + 0x20)));
      if (st->a[n] != 0)
      {
        sum = rec->v[0];
        cnt = st->a[n];
      }
      if (st->b[n] != 0)
      {
        cnt += st->b[n];
        sum += rec->v[1];
      }
      if (st->c[n] != 0)
      {
        cnt += st->c[n];
        sum += rec->v[2];
      }
      ENTS[slot].avg = ((u32) ((sum * D_8009D540) * 3600)) / ((u32) (cnt * 1000));
      ENTS[slot].b10 = *node->p48;
      node = node->next;
      n++;
    }
    while (node != 0);
    i = 0;
  }
  do
  {
    if (ENTS[i].time != 0)
    {
      d = ENTS[i].time - ENTS[0].time;
      if (d < 0)
      {
        d = -d;
      }
      ENTS[i].diff = d;
    }
    else
    {
 do { ENTS[i].diff = 0; } while (0);
    }
    i++;
  }
  while (i < 4);
  func_80098290(ENTS[4].name, TRACKS[*((u16 *) (G + 0x20))].item[0].name);
  ENTS[4].time = TRACKS[*((u16 *) (G + 0x20))].item[0].score;
  ENTS[4].avg = TRACKS[*((u16 *) (G + 0x20))].item[0].laps;
  ENTS[4].b12 = TRACKS[*((u16 *) (G + 0x20))].item[0].b4;
  if (ENTS[0].b10 < 4)
  {
    *((u16 *) (G + 0x2A)) |= 1 << (*((u16 *) (G + 0x20)));
  }
}
