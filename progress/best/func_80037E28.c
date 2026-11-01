#define U2F(x) (dv = (x), (x) < 0 ? dv += big : 0, (f32)dv)
typedef struct 
{
  s32 a;
  s32 b;
  s32 c;
} Snd;
typedef struct 
{
  char pad[0x20];
  s32 flags;
} Cam;
typedef struct 
{
  char pad[0xE];
  u16 players;
  char pad10[0xE];
  u16 mode;
} State;
typedef struct 
{
  s32 type;
  s32 rpm;
} Engine;
typedef struct 
{
  Snd *snd;
  s32 last;
  s32 w[5];
  s32 load;
} Audio;
typedef struct Car
{
  char pad0[4];
  struct Car *next;
  char pad8[0x40];
  s32 *speed;
  Engine *eng;
  s32 *surface;
  char pad54[0x14];
  Audio *audio;
  char pad6C[0x14];
  char *wheels;
  char pad84[8];
  u8 *ctrl;
  char pad90[4];
  s32 *kind;
} Car;
s32 func_8001FEE8(Car *);
Cam *func_8004240C(s32);
void func_80086AD8(Snd *, s32);
void func_80086B34(Snd *);
s32 func_80086D34(Snd *);
void func_80086D90(Snd *, s32);
void func_80086E8C(Snd *, f32);
extern s32 D_8009F640;
extern const f64 D_800A4AC8;
extern const f64 D_800A4AD0;
extern const f64 D_800A4AD8;
extern char D_800AE850[];
extern State *D_800C35A0;
extern f32 D_800C35E4;
extern f32 D_800C35E8;
extern f32 D_800C35E0;
extern u8 D_800C35C8;
extern Snd *D_800C81D4;
extern Cam *D_800C7F84;
extern u8 D_800B6818;
static inline f32 inline_fn(s32 arg0)
{
  return (f32) (120 - arg0);
}

void func_80037E28(void)
{
  Car *car;
  Audio *audio;
  Snd *snd;
  s32 new_var;
  Snd *snd1;
  f32 *vols;
  f32 *pv;
  f32 f;
  f32 g;
  f32 t;
  f32 fu;
  f64 dv;
  f64 big;
  s32 rpm;
  s32 kind;
  s32 spd;
  s32 k;
  s32 u;
  u32 sum;
  u16 mode;
  u8 ok;
  u8 gear;
  u8 i;
  ok = 0;
  if (!(D_8009F640 & 1))
  {
    ok = 1;
  }
  else
    if ((D_800C35A0->players == 2) && (!(D_8009F640 & 2)))
  {
    ok = 1;
  }
  if (!ok)
  {
    return;
  }
  car = *(*((Car ***) (D_800AE850 + 0x73F0)));
  if (car == NULL)
  {
    return;
  }
  vols = &D_800C35E4;
  big = D_800A4AC8;
  do
  {
    pv = &vols[1];
    audio = car->audio;
    rpm = car->eng->rpm;
    snd = audio->snd;
    kind = (*car).kind[1];
    spd = car->speed[3] / 5;
    switch (car->eng->type)
    {
      case 0:
        break;

      case 1:
        if (((kind == 1) && (!(D_8009F640 & 4))) && func_80086D34(&snd[4]))
      {
        D_8009F640 |= 4;
        func_80086B34(&snd[4]);
        func_80086D90(&snd[4], D_800C35E8 * 150.0f);
      }
        break;

      case 2:
        f = audio->load;
        if (f > 12000.0f)
      {
        f = 12000.0f;
      }
        mode = D_800C35A0->mode;
        f = (100.0f - (f * 0.008333334f)) * 0.01f;
        if ((mode == 6) || (mode == 7))
      {
        D_800C35E4 = 0.0f;
        if (D_800C35C8 != 0xFF)
        {
          func_80086D90(&D_800C81D4[D_800C35C8], 0);
        }
      }
      else
      {
        new_var = kind;
        if (new_var != 1)
        {
          if (((mode == 5) && (D_800B6818 == 0)) || ((D_800C35A0->players == 2) && ((mode == 5) || ((mode != 0) & (mode < 5)))))
          {
            f = 0.0f;
          }
        }
        if (new_var == 1)
        {
          g = func_8001FEE8(car);
          if (g < 0.0f)
          {
            g = -g;
          }
          if (g > 100.0f)
          {
            g = 100.0f;
          }
          D_800C35E4 = D_800C35E0 * ((1.0f - (g * 0.004f)) * 112.0f);
          D_800C7F84 = func_8004240C(1);
          if (D_800C7F84->flags & 0x880000)
          {
            D_800C35E4 *= 0.6666667f;
          }
          if (D_800C35C8 != 0xFF)
          {
            if (mode || spd)
            {
              func_80086D90(&D_800C81D4[D_800C35C8], D_800C35E4);
            }
            else
            {
              func_80086D90(&D_800C81D4[D_800C35C8], D_800C35E4);
            }
          }
        }
      }
        if (kind == 2)
      {
        break;
      }
        if (func_80086D34(&snd[4]) && ((D_800C35A0->players != 2) | (kind == 1)))
      {
        if (func_80086D34(&snd[0]))
        {
          func_80086B34(&snd[0]);
        }
        if (func_80086D34(&snd[1]))
        {
          func_80086B34(&snd[1]);
        }
      }
        if (snd[0].b == 0)
      {
        break;
      }
        t = ((rpm * 12) * D_800A4AD0) - D_800A4AD8;
        func_80086E8C(&snd[0], t);
        snd1 = &snd[1];
        func_80086E8C(snd1, t);
        if (rpm < 4000)
      {
        func_80086D90(&snd[0], f * ((*pv) * 120.0f));
        u = spd + 30;
        func_80086D90(snd1, (U2F(u) * f) * (*pv));
      }
      else
        if (rpm < 5500)
      {
        k = ((rpm - 4000) * 40) / 1500;
        func_80086D90(&snd[0], (inline_fn(k) * f) * (*pv));
        k = k + (spd + 30);
        func_80086D90(snd1, (U2F(k) * f) * (*pv));
      }
      else
      {
        func_80086D90(&snd[0], f * ((*pv) * 80.0f));
        u = spd + 80;
        func_80086D90(snd1, (U2F(u) * f) * (*pv));
      }
        if (kind != 1)
      {
        break;
      }
        gear = car->ctrl[0x337];
        if (gear != 0)
      {
        if (gear >= 3)
        {
          gear = 2;
        }
        if (func_80086D34(&snd[5]))
        {
          func_80086B34(&snd[5]);
          func_80086D90(&snd[5], ((f32) gear) * (D_800C35E8 * 56.0f));
        }
      }
        if (audio->last != (*car->surface))
      {
        audio->last = *car->surface;
        func_80086B34(&snd[3]);
        func_80086D90(&snd[3], *pv);
        func_80086D90(&snd[0], (*pv) * 80.0f);
        func_80086D90(&snd[1], (*pv) * 80.0f);
      }
        sum = 0;
        for (i = 0; i < 4; i++)
      {
        if ((*((s32 *) ((car->wheels + (i * 4)) + 0x310))) < 0)
        {
          sum += car->audio->w[i];
        }
      }

        if (sum > 2000)
      {
        if (func_80086D34(&snd[2]))
        {
          func_80086B34(&snd[2]);
        }
        if (sum > 8000)
        {
          func_80086D90(&snd[2], D_800C35E8 * 140.0f);
        }
        else
          if (sum > 6000)
        {
          func_80086D90(&snd[2], D_800C35E8 * 120.0f);
        }
        else
          if (sum > 4000)
        {
          func_80086D90(&snd[2], D_800C35E8 * 100.0f);
        }
        else
        {
          func_80086D90(&snd[2], D_800C35E8 * 80.0f);
        }
      }
      else
      {
        func_80086AD8(&snd[2], 1);
      }
        break;

    }

    car = car->next;
  }
  while (car != NULL);
}

