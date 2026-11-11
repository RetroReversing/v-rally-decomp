extern s32 D_800D065C;
extern u8 gStreamState[];
extern s32 D_800B6164;
extern s32 gSnapIndex;
extern u8 D_8009EB90[];
extern volatile unsigned long func_8001FEDC(void);
typedef struct 
{
  u8 pad[0x60];
  void *motion;
  u8 p[8];
  void *cfg;
  u8 q[0x1C];
  void *state;
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

/* Drive/brake controller for one frame. Reads the speed and motion mode,
 * computes the target speed from the track table (or the reverse-gear
 * target when the mode is 3), and writes the throttle (c->lo) or brake
 * (c->hi) with a rate limit. Stores the boost counter back to the motion
 * block. */
void func_80033F20(A *a, B *b, C *c)
{
  s32 speed = func_8001FEDC();
  s32 cfgMode;
  unsigned int req;
  s32 target;
  s32 maxVal;
  int threshold;
  s32 rate;
  s32 boost;
  s32 mode;
  s32 rev;
  s32 delta;
  s32 minVal;
  void *st = a->state;
  void *motion = a->motion;
  void *cfg = a->cfg;
  maxVal = *((s32 *) (((u8 *) st) + 0x578));
  rate = *((s32 *) (((u8 *) st) + 0x57C));
  boost = *((s32 *) (((u8 *) motion) + 0x170));
  mode = *((s32 *) (((u8 *) motion) + 0x160));
  rev = *((s32 *) (((u8 *) motion) + 0x164));
  threshold = 1800;
  cfgMode = *((s32 *) (((u8 *) cfg) + 0x34));
  if (boost)
  {
    rate = 255;
    maxVal = 12000;
    boost--;
  }
  if (cfgMode < 50)
  {
    if (mode == 3)
    {
      goto special;
    }
    target = b->value;
    if (b->limit < 30)
    {
      target = 12000;
    }
    {
      u8 *p = *((u8 **) (((u8 *) b->root) + 0x78));
      u8 n = p[27];
      if ((n && (b->index < n)) && (((s32) (*((u16 *) (p + 24)))) < target))
      {
        target = *((u16 *) (p + 24));
      }
    }
    minVal = *((s32 *) (D_8009EB90 + (gSnapIndex * 24)));
    req = target;
    if (req < minVal)
    {
      target = minVal;
    }
    if (target > maxVal)
    {
      target = maxVal;
    }
    *(s32 *)((gStreamState + 0x10000) + 0x3AE) = target;
    D_800B6164 = b->limit;
    delta = target - __builtin_abs(speed);
    if (speed < threshold)
    {
      rate = 255;
    }
    if (rate < delta)
    {
      delta = rate;
    }
    else
      if (delta < (-rate))
    {
      delta = -rate;
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
    target = (rev == 3) ? (-2000) : 0;
    delta = target - speed;

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
  *((s32 *) (((u8 *) a->motion) + 0x170)) = boost;
}
