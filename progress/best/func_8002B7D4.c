static inline static static static int __repair_inline_sum(int left, int right)
{
  return left + right;
}

extern s32 func_8002D6E0(s32 *, s32 *, s32, s32);
typedef struct 
{
  s32 a;
  s32 pad;
} Slot;
static inline static static u8 *inline_fn(u8 *arg0)
{
  return arg0 + 0x8C;
}

void func_8002B7D4(u8 *arg0)
{
  Slot sl[6];
  u8 *t0;
  s32 a0;
  s32 v1;
  s32 __repair_v1_1;
  s32 a1;
  s32 a2;
  s32 *new_var;
  s32 a3;
  s32 s0;
  s32 v0;
  s32 t1;
  u8 *p58;
  p58 = *((u8 **) (arg0 + 0x58));
  t0 = *((u8 **) (*((u8 **) inline_fn(arg0))));
  a0 = *((s32 *) (*((u8 **) (arg0 + 0x60))));
  a2 = *((s32 *) (p58 + 0xC));
  v1 = *((u16 *) (t0 + 0x8A));
  a0 = a0 * v1;
  a1 = *((s32 *) (t0 + 0x4C));
  sl[0].a = a2;
  a3 = *((s32 *) ((*((u8 **) (arg0 + 0x58))) + 0x14));
  sl[1].a = a3;
  a2 = a2 - (*((s32 *) (t0 + 0x24)));
  sl[0].a = a2;
  a3 = a3 - (*((s32 *) (t0 + 0x2C)));
  sl[1].a = a3;
  a0 = a0 + a1;
  t1 = a0 - 2;
  a0 = a0 + 2;
  a1 = *((s32 *) (t0 + 0x54));
  __repair_v1_1 = a0 * 6;
  a0 = t1 * 6;
  v0 = __repair_inline_sum(__repair_v1_1, a1);
  s0 = *((s16 *) v0);
  a1 = a0 + a1;
  v0 = *((s16 *) a1);
  s0 = s0 - v0;
  sl[2].a = s0;
  v0 = *((s32 *) (t0 + 0x54));
  __repair_v1_1 = __repair_v1_1 + v0;
  __repair_v1_1 = *((s16 *) (__repair_v1_1 + 4));
  v0 = a0 + v0;
  v0 = *((s16 *) (v0 + 4));
  ;
  sl[3].a = __repair_v1_1 - v0;
  v0 = *((s32 *) (t0 + 0x54));
  v0 = a0 + v0;
  v0 = *((s16 *) v0);
  a2 = a2 - v0;
  s0 = s0 * a2;
  sl[4].a = a2;
  a0 = a0 + (*((s32 *) (t0 + 0x54)));
  v0 = *((s16 *) (a0 + 4));
  a3 = a3 - v0;
  __repair_v1_1 = __repair_v1_1 * a3;
  s0 = s0 + __repair_v1_1;
  sl[5].a = a3;
  func_8002D6E0(&sl[2].a, &sl[2].a, a2, a3);
  v0 = s0 * 100;
  v1 = (t1 = sl[2].a) + sl[3].a;
  new_var = (s32 *) ((*((u8 **) (arg0 + 0x60))) + 0x17C);
  *new_var = v0 / v1;
}
