extern u8 D_800AE850[];
extern s32 D_800C782C;
s32 func_80089554(void *arg0, s32 arg1)
{
  int __repair_literal;
  u8 *base;
  u8 scratch[32];
  unsigned short new_var2;
  u8 **new_var;
  u8 *p;
  s32 n;
  s32 i;
  s32 bestv;
  s32 best;
  u32 flag;
  s32 value;
  n = D_800C782C;
  base = *((u8 **) (D_800AE850 + 0x80A0));
  i = 0;
  if (n > 0)
  {
    best = n;
    p = base;
    do
    {
      if ((*((s32 *) p)) == 0)
      {
        return i;
      }
      i += 1;
      p += 0x134;
    }
    while (i < best);
    base = *((u8 **) (D_800AE850 + 0x80A0));
  }
  bestv = 0x7FFFFFFF;
  best = -1;
  n = D_800C782C;
  i = 0;
  if (n > 0)
  {
    s32 limit = n;
    p = base + 0x44;
    do
    {
      flag = *((u16 *) (p + 0x5A));
      new_var2 = flag;
      if ((new_var2 != 0) && ((*((s32 *) p)) <= bestv))
      {
        bestv = *((s32 *) p);
        best = i;
      }
      i += 1;
      p += 0x134;
    }
    while (i < limit);
  }
  new_var = &(*((u8 **) (D_800AE850 + 0x80A0)));
  if (best != (-1))
  {
    return best;
  }
  n = D_800C782C;
  base = *new_var;
  i = 0;
  __repair_literal = 0;
  best = n > __repair_literal;
  if (best)
  {
    flag = *((u16 *) (base + 0x9E));
    best = n;
    do
    {
      if ((flag == 0) && ((*((void **) (base + 0x70))) != arg0))
      {
        return i;
      }
      i += 1;
    }
    while (i < best);
    n = D_800C782C;
    base = *((u8 **) (D_800AE850 + 0x80A0));
  }
  i = 0;
  if (n > 0)
  {
    best = n;
    p = base + 0x78;
    do
    {
      if (((*((void **) (p - 8))) == arg0) && (((s32 *) (*((u8 **) (((u8 *) arg0) + 4))))[arg1] == (*((s32 *) p))))
      {
        return i;
      }
      i += 1;
      p += 0x134;
    }
    while (i < best);
  }
  return arg1 % D_800C782C;
}
