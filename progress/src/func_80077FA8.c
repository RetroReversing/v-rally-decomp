extern u8 *D_800C35A0;
extern u8 D_800AE850[];
u8 func_80077FA8(u8 arg0)
{
  u32 *p;
  u32 *q;
  u8 i;
  u8 n;
  u32 *new_var;
  u32 *tbl;
  u32 t;
  u32 idx;
  int new_var2;
  n = 4;
  idx = arg0 << 5;
  t = (u32) D_800C35A0;
  t = *((u16 *) (t + 0x1E));
  new_var = ((u32 *) (D_800AE850 + 0x6DAC)) + t;
  tbl = new_var;
  p = (u32 *) (((u8 *) tbl) + idx);
  new_var2 = 1;
  i = 0;
  do
  {
    q = tbl + (i * 8);
    if ((*p) < (*q))
    {
      n--;
    }
    i++;
  }
  while (i < 4);
  return n - new_var2;
}

