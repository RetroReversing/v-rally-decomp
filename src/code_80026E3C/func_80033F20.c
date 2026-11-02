#include "decompdecomp_sync_dbba70193bdbe4bf36bd.h"
#line 1 "func.c"
extern s32 D_800D065C;
extern u8 D_800C02AE[];
extern s32 D_800B6164;
extern s32 D_8009EB80;
extern u8 D_8009EB90[];
extern volatile unsigned long func_8001FEDC(void);
typedef struct 
{
  u8 pad[0x60];
  void *motion;
  u8 p[8];
  void *gate;
  u8 q[0x1C];
  void *ctx;
} A;
typedef struct 
{
  void *root;
  u8 p[8];
  s32 index;
  s32 value;
  u8 q[8];
  s32 limit;
} B;
typedef struct 
{
  u8 p0;
  u8 flags;
  u8 status;
  u8 result;
  u8 lo;
  u8 hi;
} C;
static inline static static int inline_fn(C *arg0)
{
  return ~arg0->flags;
}

void func_80033F20(A *a, B *b, C *c)
{
  s32 speed = func_8001FEDC();
  s32 new_var3;
  unsigned int new_var2;
  s32 x;
  s32 cap;
  int new_var4;
  s32 slew;
  s32 t;
  s32 mode;
  s32 rev;
  s32 delta;
  s32 lim;
  int new_var;
  void *state = a->ctx;
  void *motion = a->motion;
  void *cfg = a->gate;
  cap = *((s32 *) (((u8 *) state) + 0x578));
  slew = *((s32 *) (((u8 *) state) + 0x57C));
  t = *((s32 *) (((u8 *) motion) + 0x170));
  mode = *((s32 *) (((u8 *) motion) + 0x160));
  rev = *((s32 *) (((u8 *) motion) + 0x164));
  new_var4 = 1800;
  new_var3 = *((s32 *) (((u8 *) cfg) + 0x34));
  if (t)
  {
    slew = 255;
    cap = 12000;
    t--;
  }
  if (new_var3 < 50)
  {
    if (mode == 3)
    {
      goto special;
    }
    x = b->value;
    if (b->limit < 30)
    {
      x = 12000;
    }
    {
      u8 *p = *((u8 **) (((u8 *) b->root) + 0x78));
      u8 n = p[27];
      if ((n && (b->index < n)) && (((s32) (*((u16 *) (p + 24)))) < x))
      {
        x = *((u16 *) (p + 24));
      }
    }
    lim = *((s32 *) (D_8009EB90 + (D_8009EB80 * 24)));
    new_var2 = x;
    if (new_var2 < lim)
    {
      x = lim;
    }
    if (x > cap)
    {
      x = cap;
    }
    *(s32 *)((D_800C02AE + 0x10000) + 0x3AE) = x;
    D_800B6164 = b->limit;
    delta = x - __builtin_abs(speed);
    if (speed < new_var4)
    {
      slew = 255;
    }
    if (slew < delta)
    {
      delta = slew;
    }
    else
      if (delta < (-slew))
    {
      delta = -slew;
    }
    if (delta > 0)
    {
      c->lo = delta;
      c->hi = 0;
      c->flags &= 239;
    }
    else
    {
      c->lo = 0;
      c->hi = -delta;
    }
    goto done;
    special:
    x = (rev == 3) ? (-2000) : 0;
    delta = x - speed;

    if (delta > 255)
    {
      delta = 255;
    }
    else
      if (delta < (-255))
    {
      delta = -255;
    }
    if (delta >= 0)
    {
      c->lo = 0;
      c->hi = 255;
      c->flags |= 16;
    }
    else
    {
      c->lo = -delta;
      c->hi = 0;
    }
  }
  else
  {
    c->lo = 0;
  }
  done:
  c->status = c->status | ~c->flags | 16;

  c->result = c->flags & c->status;
  *((s32 *) (((u8 *) a->motion) + 0x170)) = t;
}

