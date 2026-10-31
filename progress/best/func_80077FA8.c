extern u8 *D_800C35A0;
extern u8 D_800AE850[];
u8 func_80077FA8(u8 arg0)
{
  u32 *new_var;
  u8 i;
  u8 n;
  u32 *tbl;
  n = 4;
  tbl = (u32 *) ((D_800AE850 + 0x6DAC) - (-((*((u16 *) (D_800C35A0 + 0x1E))) * 4)));
  new_var = &tbl[arg0 * 8];
  i = 0;
  do
  {
    if ((*new_var) < tbl[i * 8])
    {
      n--;
    }
    i++;
  }
  while (i < 4);
  return n - 1;
}

