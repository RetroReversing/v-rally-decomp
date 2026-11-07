#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} Vec3s;
typedef struct 
{
  s32 pad0;
  s16 val;
  Vec3s pos;
} Node12;
typedef struct 
{
  u8 pad0[0xE];
  u8 e;
  u8 f;
  u8 pad10[4];
  u8 b14;
  u8 b15;
  u8 b16;
  u8 b17;
  u8 pad18[4];
  Node12 *nodes;
} Info;
typedef struct Car
{
  u8 pad0[0xA];
  u16 flags;
  u8 padC[0x40];
  s32 index4C;
  u8 pad50[4];
  u8 *points54;
  struct Car *target;
  struct Car *next;
  u8 pad60[0x18];
  Info *info;
  u8 pad7C[0xC];
  u16 count;
  u16 stride8A;
} Car;
extern void func_8002FFA4(void *, s32, s16, void *);
extern s32 func_8003035C(void *, s32, void *);
void func_80032AE4(Car *arg0)
{
  Vec3s a;
  Vec3s b;
  Vec3s c;
  Car *car;
  Car *t;
  struct Car *new_var;
  Info *g;
  s32 v;
  s32 __repair_phase_v;
  u8 e;
  u8 f;
  s32 i;
  s32 start;
  s32 far;
  s32 near;
  car = arg0;
  do
  {
    if (car->target == NULL)
    {
      goto next;
    }
    if (car->flags & 0x800)
    {
      goto next;
    }
    if (!(car->target->flags & 0x800))
    {
      goto next;
    }
    g = car->info;
    {
      u8 bb;
      Info *h = g;
      bb = h->b15;
      v = bb ? bb : h->b16;
    }
    if (v == 0)
    {
      goto next;
    }
    v = (v - car->info->b14) * 4;
    e = car->info->e;
    f = car->info->f;
    if (f < e)
    {
      i = f;
    }
    else
    {
      i = e;
    }
    if ((i < 1) || (i > 3))
    {
      goto next;
    }
    far = car->target->info->b17;
    near = car->target->info->b14;
    v = far - v;
    new_var = car->target;
    t = new_var;
    if (v < 20)
    {
      v = 20;
    }
    if (v > 80)
    {
      v = 80;
    }
    {
      s32 n = (i * 2) + 1;
      start = t->count - n;
    }
    func_8002FFA4(t, start, v, &a);
    func_8002FFA4(t, t->count - 1, far, &b);
    for (i = start; i <= (t->count - 1); i++)
    {
      __repair_phase_v = start + 1;
      c.x = b.x - a.x;
      c.x = (c.x * (i - start)) / (t->count - __repair_phase_v);
      c.x = c.x + a.x;
      c.y = b.y - a.y;
      c.y = (c.y * (i - start)) / (t->count - __repair_phase_v);
      c.y = c.y + a.y;
      c.z = b.z - a.z;
      c.z = (c.z * (i - start)) / (t->count - __repair_phase_v);
      c.z = c.z + a.z;
      t->info->nodes[i].pos.x = c.x;
      t->info->nodes[i].pos.y = c.y;
      t->info->nodes[i].pos.z = c.z;
      t->info->nodes[i].val = (s16) func_8003035C(t, i, &c);
    }

    b = a;
    func_8002FFA4(t, 0, near, &a);
    for (i = 0; i <= start; i++)
    {
      c.x = b.x - a.x;
      c.x = (c.x * i) / start;
      c.x = c.x + a.x;
      c.y = b.y - a.y;
      c.y = (c.y * i) / start;
      c.y = c.y + a.y;
      c.z = b.z - a.z;
      c.z = (c.z * i) / start;
      c.z = c.z + a.z;
      t->info->nodes[i].pos.x = c.x;
      t->info->nodes[i].pos.y = c.y;
      t->info->nodes[i].pos.z = c.z;
      t->info->nodes[i].val = (s16) func_8003035C(t, i, &c);
    }

    next:
    car = car->next;

  }
  while ((car != arg0) && (car != NULL));
}

