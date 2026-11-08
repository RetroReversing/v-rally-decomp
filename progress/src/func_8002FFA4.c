#define PTS(off) (*(u16 *)((off) + *(u8 **)(arg0 + 0x54)))
#define COORD(off, c) (*(u16 *)(*(u8 **)(arg0 + 0x54) + (((off)/2 + (c)) * 2)))
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} RRInterpPoint;
void func_8002FFA4(void *o, s32 arg1, s16 arg2, void *out)
{
  u8 *arg0 = (u8 *) o;
  s16 d[3];
  s32 t;
  s32 prev;
  s32 next;
  u16 *pa;
  u8 *base;
  s32 rr_index_product;
  rr_index_product = arg1 * (*((u16 *) (arg0 + 0x8A)));
  prev = rr_index_product + (*((s32 *) (arg0 + 0x4C)));
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
      base = *((u8 **) (arg0 + 0x54));
      a = prev * 6;
      b = next * 6;
      pa = (u16 *) (((u32) a) + ((u32) base));
      pb = (u16 *) (((u32) b) + ((u32) base));
      d0 = (*pa) - (*pb);
      d[0] = d0;
      new_var = 1;
      d[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y);
      d[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z);
      d[0] = (d[0] * ((s32) arg2)) / 50;
      d[1] = (d[1] * ((s32) arg2)) / 50;
      d[2] = (d[2] * ((s32) arg2)) / 50;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->x) + d[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y) + d[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z) + d[2];
    }
    else
    {
      s16 d0;
      s32 a;
      s32 b;
      u16 *pb;
      int new_var;
      base = *((u8 **) (arg0 + 0x54));
      a = arg1 * 6;
      b = prev * 6;
      pa = (u16 *) (((u32) a) + ((u32) base));
      pb = (u16 *) (((u32) b) + ((u32) base));
      d0 = *pa - *pb;
      t = ((s32) arg2) - 50;
      d[0] = d0;
      new_var = 1;
      d[1] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y);
      d[2] = ((u16) ((RRInterpPoint *) (((u32) a) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z) - ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z);
      d[0] = (d[0] * t) / 50;
      d[1] = (d[1] * t) / 50;
      d[2] = (d[2] * t) / 50;
      *((s16 *) (((u8 *) out) + 0)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->x) + d[0];
      *((s16 *) (((u8 *) out) + 2)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->y) + d[new_var];
      *((s16 *) (((u8 *) out) + 4)) = ((u16) ((RRInterpPoint *) (((u32) b) + ((u32) (*((u8 **) (arg0 + 0x54))))))->z) + d[2];
    }
  }
}

