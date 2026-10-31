extern u8 D_800ADFE0;
extern u8 D_800ADFE1;
extern u8 *D_800B5C40;
extern u8 D_800B6600[];
extern u8 *D_800C35A0;
void func_800528A4(void)
{
  u8 *obj;
  u32 i;
  u8 *table;
  u8 *node;
  u8 *new_var;
  int new_var3;
  u8 *flag;
  int new_var2;
  u32 sum;
  u32 *p;
  u32 n;
  u32 k;
  u32 min;
  u32 *row;
  obj = D_800C35A0;
  if ((*((u16 *) (obj + 0x1E))) != 5)
  {
    return;
  }
  table = D_800B6600;
  node = *((u8 **) D_800B5C40);
  flag = &D_800ADFE1;
  for (i = 0; i < 4; i += 1)
  {
    if (node == 0)
    {
      continue;
    }
    p = *((u32 **) (*((u8 **) (node + 0x6C))));
    new_var = flag;
    sum = 0;
    p += 1;
    if ((*new_var) == 0)
    {
      sum = *p;
    }
    else
      if (sum < (((u32) new_var[-1]) - 1))
    {
      n = ((u32) D_800ADFE0) - 1;
      k = 0;
      do
      {
        k += 1;
        sum += *p;
        p += 1;
      }
      while (k < n);
    }
    *((u32 *) (((table + ((*((u16 *) (obj + 0x22))) << 4)) + 0x118) + (i << 2))) = sum;
    node = *((u8 **) (node + 4));
  }

  obj = D_800C35A0;
  if ((*((u16 *) (obj + 0x2C))) & 0x4000)
  {
    new_var2 = 0x118;
    row = (u32 *) ((table + ((*((u16 *) (obj + 0x22))) << 4)) + new_var2);
    min = ~0U;
    for (i = 0; i < 4; i += 1)
    {
      if (row[i] < min)
      {
        min = row[i];
      }
    }

    new_var3 = min - 10;
    if (min >= 21)
    {
      *((u32 *) ((table + ((k = *((u16 *) (D_800C35A0 + 0x22))) << 4)) + new_var2)) = new_var3;
    }
  }
}
