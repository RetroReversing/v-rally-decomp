extern u8 D_800C02AE[];
void func_80020098(u8 *arg0, u8 arg1)
{
  u8 i;
  u8 k;
  u8 j;
  u8 prev;
  u8 cur;
  int new_var;
  u8 val;
  u8 *src;
  src = arg0;
  k = 0;
  i = 0;
  cur = src[0x93];
  if (((*((s32 *) (arg0 + 0x44))) - 1) > 0)
  {
    val = 0x44;
    do
    {
      prev = cur;
      cur = src[(i * 0x4C) + 0xDF];
      for (j = 0; j < 10; j++)
      {
        arg0 = (D_800C02AE + 0x5BAA) + (arg1 * 0x81);
        new_var = ((j * (cur - prev)) / 10) + prev;
        val = new_var;
        arg0[k] = val;
        j = val;
        if (j >= 0x80)
        {
          arg0[k] = 0x7F;
        }
        if (k < 0x80)
        {
          k++;
        }
      }

      i++;
    }
    while (i < ((*((s32 *) (src + 0x44))) - 1));
  }
  D_800C02AE[0x5C2A + (arg1 * 0x81)] = cur;
}
