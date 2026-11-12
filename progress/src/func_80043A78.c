typedef struct Pad
{
  s8 x;
  u8 b1;
  s8 b2;
  u8 b3;
  u8 b4;
  u8 b5;
} Pad;
typedef struct Ctl
{
  u8 pad00[0x20];
  s32 state;
  u32 timer;
} Ctl;
typedef struct Trk
{
  u8 pad00[0x4C];
  s32 x4C;
} Trk;
typedef struct Body
{
  u8 pad00[0x58];
  u32 x58;
  u8 pad5C[0x150 - 0x5C];
  Trk *p150;
  u8 pad154[0x578 - 0x154];
  s32 x578;
} Body;
typedef struct Info
{
  u8 pad00[8];
  s32 x8;
  u8 pad0C[4];
  s32 x10;
} Info;
typedef struct X8C
{
  u8 pad00[0x28];
  Trk *trk;
} X8C;
typedef struct Car
{
  u8 pad00[4];
  struct Car *next;
  u8 pad08[0x14 - 0x8];
  s32 flags;
  u8 pad18[0x48 - 0x18];
  s32 *player;
  u8 pad4C[0x60 - 0x4C];
  Body *body;
  u8 pad64[0x6C - 0x64];
  Info *info;
  Ctl *ctl;
  u8 pad74[0x8C - 0x74];
  X8C *x8C;
} Car;
typedef struct Snd
{
  u8 pad00[4];
  struct Snd *next;
  u8 pad08[0x24 - 0x8];
  Car *car;
  u8 data[4];
} Snd;
typedef struct Slot44
{
  u8 pad00[0xA];
  s16 hA;
  u8 pad0C[0x44 - 0xC];
} Slot44;
typedef struct Game
{
  u8 pad00[0xE];
  u16 players;
  u8 pad10[0x1E - 0x10];
  u16 state;
} Game;
extern Game *gRecords;
extern Snd **D_800B5B4C;
extern Car **gCarList;
extern s32 gRaceState; extern u8 gOrderState[];
extern Slot44 *gCarEntryTable;
extern u8 D_800A4DFC[];
extern s32 getCounterValue(void *);
extern s32 named_entry_set_value(void **, u8 *, s32);
extern void ai_drive_compute(void *, s8 *);
extern void race_reset(void);
extern void input_clear_flags(s32, s32);
s32 abs(s32);
static __inline__ void expired(s32 *st,u32 *timer) {s32 v=*st;if(!(v&8)){if(v&4){*st=(v|2)&~4;}else{*st=(v|4)&~2;} *timer=50; *st|=8;return;}*st=v|0x20;}

/* Per-car control for the race start and finish: while the car's control
 * state has bit 0x20 set, it runs the countdown and steering assist; once the
 * state clears, the finish check runs for the local players and ends the race
 * when every remaining car has finished. */
void func_80043A78(Car *car, Pad *pad)
{
  Ctl *ctl;
  s32 *state;
  u32 *timer;
  Trk *trk;
  u32 track_pos;
  s32 speed;
  s32 old_state;
  s32 timer_class;
  u32 lap_gap;
  Snd *snd;
  union { s32 player; Car *node; } n;
  s16 racers_left;
  s16 finished;
  s32 all_done;
  u8 steer;
  ctl = car->ctl;
  speed = 0;
  trk = car->x8C->trk;
  track_pos = car->body->x58;
  state = &ctl->state;
  if (!((*state) & 0x20))
  {
    timer = &ctl->timer;
    speed = getCounterValue(car);
    if (!(car->flags & 0x80))
    {
      if ((*car->player) < 4)
      {
        for (snd = *D_800B5B4C; snd != NULL; snd = snd->next)
        {
          if (snd->car == car)
          {
            break;
          }
        }

        named_entry_set_value((void **)((u8*)snd + 0x28), D_800A4DFC, 2);
      }
      car->flags |= 0x80;
      timer_class = car->info->x8;
      *timer = 250;
      if (timer_class == 2)
      {
        *timer = 238;
      }
      else
        if (timer_class == 3)
      {
        *timer = 225;
      }
      else
        if (timer_class == 4)
      {
        *timer = 210;
      }
      car->body->p150 = trk;
      car->body->x578 = 7000;
    }
    if ((*timer) != 0)
    {
      if ((*timer) >= 200)
      {
        if ((*timer) == 200)
        {
          *timer = 12;
          old_state = *state;
          *state = old_state | 1;
          if (track_pos < ((u32)trk->x4C - 1U))
          {
            *state = old_state | 5;
          }
          else
          {
            *state = old_state | 3;
          }
        }
        else
        {
          ai_drive_compute(car, (s8*)pad);
        }
      }
      else
      {
        if ((*state) & 4)
        {
          pad->x = 127;
        }
        if ((*state) & 2)
        {
          pad->x = -127;
        }
        pad->b4 = 0;
        old_state = *state;
        if (old_state & 8)
        {
          *state = old_state | 1;
        }
        else
          if (old_state & 0x10)
        {
          lap_gap = 4 - abs(trk->x4C - track_pos);
          if (lap_gap != 0)
          {
            steer = ((u32)speed + 27U) / lap_gap;
          }
          else
          {
            steer = 0;
          }
          if (pad->x > 0)
          {
            pad->x = steer;
          }
          else
          {
            pad->x = -steer;
          }
          pad->b4 = 0xFF;
          if (speed >= 0x79)
          {
            *state &= ~0x10;
          }
        }
      }
      (*timer)--;
    }
    else
    {
expired(state,timer);
    }
    if (!((*state) & 0x20))
    {
      goto end;
    }
  }
  if ((*car->player) < 4)
  {
    pad->b1 = 0;
    pad->b5 = 0;
    pad->b2 = 0xFF;
    pad->b3 = pad->b1;
    if ((gRecords->state != 0) & (gRecords->state != 5))
    {
      n.player = *car->player;
      { Slot44 *slot = gCarEntryTable + n.player; slot->hA = 2; }
      racers_left = gRecords->players;
      finished = 0;
      for (n.node = *gCarList; n.node != NULL; n.node = n.node->next)
      {
        if ((*n.node->player) < 4)
        {
          state = &n.node->ctl->state;
          if (n.node->flags & 0x100)
          {
            if (n.node->ctl->state & 0x20)
            {
              racers_left--;
            }
          }
          else
            if ((((speed >= (-5)) && (speed <= 5)) && (n.node->info->x10 == 0)) && (n.node->flags & 0x200))
          {
            finished++;
            racers_left--;
          }
        }
      }

      if ((racers_left == 0) && (finished != gRecords->players))
      {
        goto finish;
      }
    }
    else
    {
      if ((*car->player) < 4)
      {
        { Slot44 *slot=gCarEntryTable; slot += *car->player; slot->hA=2; }
      }
      racers_left = 1;
      for (n.node = *gCarList; n.node != NULL; n.node = n.node->next)
      {
        if ((*n.node->player) < 4)
        {
          all_done = -((n.node->flags & 0x100) != 0);
          racers_left &= all_done;
        }
      }

      if (racers_left)
      {
        finish:
        *(s32 *)(gOrderState + 0x8030) = 0;

        race_reset();
        input_clear_flags(0, 0x1000);
        input_clear_flags(0, 0x8000);
      }
    }
  }
  end:
  if ((*state) & 1)
  {
    pad->b1 |= 0x10;
  }

  steer = (pad->b2 | (~pad->b1)) | 0x10;
  pad->b2 = steer;
  pad->b3 = pad->b1 & steer;
}
