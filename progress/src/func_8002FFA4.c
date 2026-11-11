typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} RRInterpPoint;

/* Interpolates a point along the route at index arg1 (entries 6 bytes each, from
 * obj->points), using the fraction arg2 (0..50) between the previous and current
 * entries. Writes the x, y, z result to out. */
void func_8002FFA4(void *o, s32 arg1, s16 arg2, void *out)
{
  u8 *obj = (u8 *) o;
  s16 delta[3];
  s32 scaled;
  s32 prev;
  s32 next;
  u16 *pa;
  u8 *base;
  s32 rr_index_product;
  rr_index_product = arg1 * (*((u16 *) (obj + 0x8A)));
  prev = rr_index_product + (*((s32 *) (obj + 0x4C)));
  {
    next = prev - 2;
    arg1 = prev + 2;
    if (arg2 < 50)
    {
      s16 d0;
      s32 a;
      s32 b;
      u16 *pb;
      int new_var;
      base = *((u8 **) (obj + 0x54));
      a = prev * 6;
      b = next * 6;
      pa = (u16 *) (((u32) a) + ((u32) base));
      pb = (u16 *) (((u32) b) + ((u32) base));
      d0 = (*pa) - (*pb);
      delta[0] = d0;
      new_var = 1;
      delta[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y);
      delta[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z);
      delta[0] = (delta[0] * ((s32) arg2)) / 50;
      delta[1] = (delta[1] * ((s32) arg2)) / 50;
      delta[2] = (delta[2] * ((s32) arg2)) / 50;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->x) + delta[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y) + delta[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z) + delta[2];
    }
    else
    {
      s16 d0;
      s32 a;
      s32 b;
      u16 *pb;
      int new_var;
      base = *((u8 **) (obj + 0x54));
      a = arg1 * 6;
      b = prev * 6;
      pa = (u16 *) (((u32) a) + ((u32) base));
      pb = (u16 *) (((u32) b) + ((u32) base));
      d0 = *pa - *pb;
      scaled = ((s32) arg2) - 50;
      delta[0] = d0;
      new_var = 1;
      delta[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y);
      delta[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (obj + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z);
      delta[0] = (delta[0] * scaled) / 50;
      delta[1] = (delta[1] * scaled) / 50;
      delta[2] = (delta[2] * scaled) / 50;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->x) + delta[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->y) + delta[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (obj + 0x54))))))->z) + delta[2];
    }
  }
}
