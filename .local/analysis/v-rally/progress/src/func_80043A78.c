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
extern Game *D_800C35A0;
extern Snd **D_800B5B4C;
extern Car **D_800B5C40;
extern s32 D_800B6880; extern u8 D_800AE850[];
extern Slot44 *D_800A1234;
extern u8 D_800A4DFC[];
extern s32 func_8001FEE8(void *);
extern s32 func_80022374(void **, u8 *, s32);
extern void func_800347A4(void *, s8 *);
extern void func_80042F40(void);
extern void func_80085778(s32, s32);
static __inline__ void expired(s32 *st,u32 *timer) {s32 v=*st;if(!(v&8)){if(v&4){*st=(v|2)&~4;}else{*st=(v|4)&~2;} *timer=50; *st|=8;return;}*st=v|0x20;}
void func_80043A78(Car *car, Pad *pad)
{
  Ctl *ctl;
  s32 *st;
  u32 *timer;
  Trk *trk;
  u32 pos;
  s32 speed;
  s32 v;
  s32 d;
  u32 q;
  Snd *s;
  union { s32 player; Car *node; } n;
  s16 cnt;
  s16 k;
  s32 all;
  u8 t;
  ctl = car->ctl;
  speed = 0;
  trk = car->x8C->trk;
  pos = car->body->x58;
  st = &ctl->state;
  if (!((*st) & 0x20))
  {
    timer = &ctl->timer;
    speed = func_8001FEE8(car);
    if (!(car->flags & 0x80))
    {
      if ((*car->player) < 4)
      {
        for (s = *D_800B5B4C; s != NULL; s = s->next)
        {
          if (s->car == car)
          {
            break;
          }
        }

        func_80022374((void **)((u8*)s + 0x28), D_800A4DFC, 2);
      }
      car->flags |= 0x80;
      d = car->info->x8;
      *timer = 250;
      if (d == 2)
      {
        *timer = 238;
      }
      else
        if (d == 3)
      {
        *timer = 225;
      }
      else
        if (d == 4)
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
          v = *st;
          *st = v | 1;
          if (pos < ((u32)trk->x4C - 1U))
          {
            *st = v | 5;
          }
          else
          {
            *st = v | 3;
          }
        }
        else
        {
          func_800347A4(car, (s8*)pad);
        }
      }
      else
      {
        if ((*st) & 4)
        {
          pad->x = 127;
        }
        if ((*st) & 2)
        {
          pad->x = -127;
        }
        pad->b4 = 0;
        v = *st;
        if (v & 8)
        {
          *st = v | 1;
        }
        else
          if (v & 0x10)
        {
          q = 4 - abs(trk->x4C - pos);
          if (q != 0)
          {
            t = ((u32)speed + 27U) / q;
          }
          else
          {
            t = 0;
          }
          if (pad->x > 0)
          {
            pad->x = t;
          }
          else
          {
            pad->x = -t;
          }
          pad->b4 = 0xFF;
          if (speed >= 0x79)
          {
            *st &= ~0x10;
          }
        }
      }
      (*timer)--;
    }
    else
    {
expired(st,timer);
    }
    if (!((*st) & 0x20))
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
    if ((D_800C35A0->state != 0) & (D_800C35A0->state != 5))
    {
      n.player = *car->player;
      { Slot44 *slot = D_800A1234 + n.player; slot->hA = 2; }
      cnt = D_800C35A0->players;
      k = 0;
      for (n.node = *D_800B5C40; n.node != NULL; n.node = n.node->next)
      {
        if ((*n.node->player) < 4)
        {
          st = &n.node->ctl->state;
          if (n.node->flags & 0x100)
          {
            if (n.node->ctl->state & 0x20)
            {
              cnt--;
            }
          }
          else
            if ((((speed >= (-5)) && (speed <= 5)) && (n.node->info->x10 == 0)) && (n.node->flags & 0x200))
          {
            k++;
            cnt--;
          }
        }
      }

      if ((cnt == 0) && (k != D_800C35A0->players))
      {
        goto finish;
      }
    }
    else
    {
      if ((*car->player) < 4)
      {
        { Slot44 *slot=D_800A1234; slot += *car->player; slot->hA=2; }
      }
      cnt = 1;
      for (n.node = *D_800B5C40; n.node != NULL; n.node = n.node->next)
      {
        if ((*n.node->player) < 4)
        {
          all = -((n.node->flags & 0x100) != 0);
          cnt &= all;
        }
      }

      if (cnt)
      {
        finish:
        *(s32 *)(D_800AE850 + 0x8030) = 0;

        func_80042F40();
        func_80085778(0, 0x1000);
        func_80085778(0, 0x8000);
      }
    }
  }
  end:
  if ((*st) & 1)
  {
    pad->b1 |= 0x10;
  }

  t = (pad->b2 | (~pad->b1)) | 0x10;
  pad->b2 = t;
  pad->b3 = pad->b1 & t;
}

