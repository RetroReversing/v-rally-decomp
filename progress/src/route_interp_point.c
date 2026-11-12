typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} RRInterpPoint;

/* Interpolates a route point between the two neighbouring entries of the route at idx
 * (6-byte entries in obj->points, index stride from obj+0x8A), blending by frac (0..500).
 * Writes the x, y, z result to out. */
#ifdef PORT
void route_interp_point(void *o, s32 idx, s16 frac, s16 *out)
{
  u8 *obj = (u8 *) o;
  s16 delta[3];
  s32 scaled;
  s32 prev_idx;
  s32 next_idx;
  s32 idx_stride;
  u8 *points;
  RRInterpPoint *pa;
  RRInterpPoint *pb;
  idx_stride = idx * (*((u16 *) (obj + 0x8A)));
  prev_idx = idx_stride + (*((s32 *) (obj + 0x4C)));
  next_idx = prev_idx - 2;
  idx = prev_idx + 2;
  points = *((u8 **) (obj + 0x54));
  if (frac < 500)
  {
    pa = (RRInterpPoint *) (points + prev_idx * 6);
    pb = (RRInterpPoint *) (points + next_idx * 6);
    scaled = (s32) frac;
  }
  else
  {
    pa = (RRInterpPoint *) (points + idx * 6);
    pb = (RRInterpPoint *) (points + prev_idx * 6);
    scaled = ((s32) frac) - 500;
  }
  delta[0] = (u16) pa->x - (u16) pb->x;
  delta[1] = (u16) pa->y - (u16) pb->y;
  delta[2] = (u16) pa->z - (u16) pb->z;
  delta[0] = (delta[0] * scaled) / 500;
  delta[1] = (delta[1] * scaled) / 500;
  delta[2] = (delta[2] * scaled) / 500;
  out[0] = (u16) pb->x + delta[0];
  out[1] = (u16) pb->y + delta[1];
  out[2] = (u16) pb->z + delta[2];
}
#else
void route_interp_point(void *o, s32 idx, s16 frac, s16 *out)
{
  u8 *obj = (u8 *) o;
  s16 delta[3];
  s32 scaled;
  s32 prev_idx;
  s32 next_idx;
  u16 *pt_a;
  u8 *points;
  s32 idx_stride;
  idx_stride = idx * (*((u16 *) (obj + 0x8A)));
  prev_idx = idx_stride + (*((s32 *) (obj + 0x4C)));
  {
    next_idx = prev_idx - 2;
    idx = prev_idx + 2;
    if (frac < 500)
    {
      s16 d0;
      s32 a;
      s32 b;
      u16 *pt_b;
      int new_var;
      points = *((u8 **) (obj + 0x54));
      a = prev_idx * 6;
      b = next_idx * 6;
      pt_a = (u16 *) (((u32) a) + ((u32) points));
      pt_b = (u16 *) (((u32) b) + ((u32) points));
      d0 = (*pt_a) - (*pt_b);
      delta[0] = d0;
      new_var = 1;
      delta[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y);
      delta[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z);
      delta[0] = (delta[0] * ((s32) frac)) / 500;
      delta[1] = (delta[1] * ((s32) frac)) / 500;
      delta[2] = (delta[2] * ((s32) frac)) / 500;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->x) + delta[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y) + delta[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z) + delta[2];
    }
    else
    {
      s16 d0;
      s32 a;
      s32 b;
      u16 *pt_b;
      int new_var;
      points = *((u8 **) (obj + 0x54));
      a = idx * 6;
      b = prev_idx * 6;
      pt_a = (u16 *) (((u32) a) + ((u32) points));
      pt_b = (u16 *) (((u32) b) + ((u32) points));
      d0 = *pt_a - *pt_b;
      scaled = ((s32) frac) - 500;
      delta[0] = d0;
      new_var = 1;
      delta[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y);
      delta[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z);
      delta[0] = (delta[0] * scaled) / 500;
      delta[1] = (delta[1] * scaled) / 500;
      delta[2] = (delta[2] * scaled) / 500;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->x) + delta[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y) + delta[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z) + delta[2];
    }
  }
}
#endif
