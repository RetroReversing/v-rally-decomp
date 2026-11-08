typedef struct 
{
  u32 a;
  s32 b;
} Split;
typedef struct 
{
  u8 pad0[8];
  s16 checkpoint;
  u8 pad0A[0x24 - 0xA];
  s32 x;
  u8 pad28[4];
  s32 z;
  u8 pad30[0x54 - 0x30];
  s16 *verts;
  u8 pad58[0x74 - 0x58];
  Split *splits;
  u8 pad78[0x8A - 0x78];
  u16 n;
} Track;
typedef struct 
{
  u8 pad0[0x28];
  Track *track;
} TrackRef;
typedef struct 
{
  u8 pad0[0x28];
  u32 seg;
} Progress;
typedef struct 
{
  u8 pad0[0x2B8];
  s32 x;
  u8 pad2BC[4];
  s32 z;
} Body;
typedef struct 
{
  s32 *times;
  u32 total;
  s32 position;
  s32 gap;
} RaceInfo;
typedef struct 
{
  s32 laps;
  u32 checkpoint;
  s32 count;
} LapInfo;
typedef struct Car
{
  u8 pad0[4];
  struct Car *next;
  u8 pad8[0x14 - 0x8];
  u32 flags;
  u8 pad18[0x48 - 0x18];
  s32 *p48;
  u8 pad4C[0x60 - 0x4C];
  Progress *progress;
  u8 pad64[0x6C - 0x64];
  RaceInfo *race;
  LapInfo *lap;
  u8 pad74[0x80 - 0x74];
  Body *body;
  u8 pad84[0x8C - 0x84];
  TrackRef *ref;
} Car;
typedef struct 
{
  Car *first;
} CarList;
typedef struct Cursor { s16 marker; u16 position; } Cursor;
extern Cursor D_800ADFDC;
extern s32 D_800ADFE8;
extern CarList *D_800B5C40;
extern u8 *D_800C35A0;

/* Updates one car's race standing. Before the race starts (flag at
 * D_800C35A0+0x1E clear) it only records the car's split at a new checkpoint.
 * Otherwise it updates the lap counter from the checkpoint change, counts how
 * many other cars are ahead on track position (lap, then track segment, then
 * the projection onto the segment direction), sets the gap to the car in
 * front, and on a checkpoint change stores the split time. */
void func_80044908(Car *car)
{
  s32 va[4];
  s32 vb[4];
  s32 vc[4];
  LapInfo *lap;
  u32 oldCp;
  u32 cp;
  s32 pos;
  u32 sum;
  Track *trk;
  Split *e;
  Car *other;
  s32 laps;
  s32 *new_var;
  u8 found;
  s32 i;
  s32 *tp;
  lap = car->lap;
  sum = 0;
  oldCp = lap->checkpoint;
  pos = D_800ADFDC.position;
  cp = oldCp;
  if ((*((u16 *) (D_800C35A0 + 0x1E))) == 0)
  {
    if (((*car->p48) < 4) && (!(car->flags & 0x100)))
    {
      trk = car->ref->track;
      lap->checkpoint = trk->checkpoint;
      if (oldCp != trk->checkpoint)
      {
        e = trk->splits;
        if (!(car->flags & 0x20))
        {
          pos = *car->p48;
          sum = car->race->total;
          e[pos].a = sum;
          e[pos].b = car->lap->laps;
          car->race->gap = e[4].a - e[pos].a;
        }
      }
    }
    return;
  }
  trk = car->ref->track;
  if ((cp == 0) && (trk->checkpoint == D_800ADFE8))
  {
    lap->count--;
  }
  else
    if ((cp == D_800ADFE8) && (trk->checkpoint == 0))
  {
    car->lap->count++;
  }
  else
    if (cp < ((u32) trk->checkpoint))
  {
    car->lap->count++;
  }
  else
    if (((u32) trk->checkpoint) < cp)
  {
    car->lap->count--;
  }
  car->lap->checkpoint = trk->checkpoint;
  other = D_800B5C40->first;
  laps = car->lap->count;
  for (; other != NULL; other = other->next)
  {
    if (other != car)
    {
      Track *otrk = other->ref->track;
      s32 olaps = other->lap->count;
      if (!(other->flags & 0x100))
      {
        if (olaps < laps)
        {
          pos--;
        }
        else
          if (laps == olaps)
        {
          u32 seg = car->progress->seg;
          u32 oseg = other->progress->seg;
          if ((oseg < seg) && (trk == otrk))
          {
            pos--;
          }
          else
            if (seg == oseg)
          {
#define seg_idx i
            u16 n;
            va[0] = car->body->x - trk->x;
            va[2] = car->body->z - trk->z;
            vb[0] = other->body->x - trk->x;
            vb[2] = other->body->z - trk->z;
            n = trk->n;
            seg = (seg * n) + (n >> 1);
            seg_idx = seg;
            vc[0] = trk->verts[(seg_idx + n) * 3] - trk->verts[seg_idx * 3];
            vc[2] = trk->verts[((seg_idx + n) * 3) + 2] - trk->verts[(seg_idx * 3) + 2];
            va[0] = vb[0] - va[0];
            va[2] = vb[2] - va[2];
            if (((vc[0] * va[0]) + (vc[2] * va[2])) <= 0)
            {
              pos--;
            }
          }
        }
      }
    }
  }

  car->race->position = pos;
  if (pos == 1)
  {
    car->race->gap = 0;
  }
  else
  {
    Car *o;
    found = 0;
    o = D_800B5C40->first;
    while ((!found) && (o != NULL))
    {
      if (o->race->position == (car->race->position - 1))
      {
        found = 1;
      }
      else
      {
        o = o->next;
      }
    }

    if (found)
    {
      RaceInfo *r = car->race;
      s32 g = r->gap;
      s32 og = o->race->gap;
      if (g < og)
      {
        r->gap = og;
        o->race->gap = g;
      }
    }
  }
  if (oldCp != trk->checkpoint)
  {
    e = trk->splits;
    pos--;
    if (!(car->flags & 0x20))
    {
      tp = car->race->times;
      for (i = 1; i < car->lap->laps; i++)
      {
        sum += tp[i];
      }

      sum += car->race->total;
      e[pos].a = sum;
      e[pos].b = car->lap->laps;
      if (pos != 0)
      {
        if ((e[0].b == e[pos].b) && (e[0].a != 0))
        {
          if (e[0].a < sum)
          {
            car->race->gap = sum - e[0].a;
          }
        }
        else
          if (e[pos - 1].b > e[pos].b)
        {
          car->race->gap = (e[pos - 1].b - e[pos].b) + 3600000;
        }
      }
    }
  }
}
