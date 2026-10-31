extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 D_800C81FC;
static inline static static u8 *inline_fn(u8 *arg0, u32 arg1)
{
  return arg0 + arg1;
}

void func_800529F0(void)
{
  u8 *p = *((u8 **) (D_800C02AE + 0x32F2));
  u8 *base;
  u8 *q;
  u8 *walk;
  u8 *src;
  u8 *scores;
  unsigned int off;
  u32 j;
  u32 m;
  u8 *new_var2;
  u32 k;
  u32 points;
  volatile char pad[8];
  u8 *new_var;
  u8 *new_var3;
  s32 sum;
  u32 rank;
  if ((*((u16 *) inline_fn(p, 0x1E))) == 5)
  {
    base = D_800AE850 + 0x7DB0;
    walk = base;
    new_var3 = p;
    off = 0;
    q = inline_fn(*((u8 **) inline_fn(D_800C02AE, 0x1039A)), (*((u16 *) (new_var3 + 0x20))) * 0x2C4);
    do
    {
      u16 n = *((u16 *) inline_fn(q, 0x14));
      sum = 0;
      j = 0;
      if (n)
      {
        src = base;
        do
        {
          j++;
          sum += *((s32 *) ((src + off) + 0x118));
          src += 0x10;
        }
        while (j < n);
      }
      *((s32 *) inline_fn(inline_fn(base, (*((u16 *) (new_var3 + 0x20))) << 4) + 0x58, off)) = sum;
      off += 4;
      *((s32 *) inline_fn(walk, 0x168)) += sum;
      walk += 4;
    }
    while (off < 0x10);
    m = 0;
    walk = base;
    k = 0;
    do
    {
      rank = 0;
      j = 0;
      ;
      scores = inline_fn(base + ((*((u16 *) inline_fn(new_var3, 0x20))) << 4), 0x58);
      src = scores;
      do
      {
        j++;
        rank += ((u32) (*((u32 *) src))) < (*((u32 *) inline_fn(scores, k)));
        src += 4;
      }
      while (j < 4);
      new_var = inline_fn(D_800C02AE, 0x32F2);
      new_var2 = (*((u8 **) new_var)) + 0x20;
      *((s8 *) (inline_fn(base + ((*((u16 *) new_var2)) << 2), 0x28) + m)) = rank;
      switch (rank)
      {
        case 2:
          points = 1;
          break;

        case 3:
          points = 0;
          break;

        case 0:
          D_800C81FC = m < (*((u16 *) (new_var3 + 0xE)));
          points = 4;
          break;

        case 1:
          points = 2;
          break;

      }

      k += 4;
      m++;
      *((u32 *) walk) += points;
      walk = walk + 4;
    }
    while (m < 4);
  }
}
