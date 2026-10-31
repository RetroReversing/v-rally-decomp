extern char D_800C02AE[];
void func_80023B7C(char *arg0, char *arg1)
{
  s32 *out;
  s32 *t3;
  u32 i;
  int new_var;
  s32 q;
  u32 a1;
  s32 v;
  char *cur;
  s32 *new_var2;
  char *tab;
  s32 saved;
  out = *((s32 **) (arg1 + 0x78));
  t3 = *((s32 **) (arg1 + 0x20));
  *((s32 *) (((char *) out) + 0x60)) = *((s32 *) (arg0 + 0x90));
  out[0] = *((s32 *) (arg0 + 0xDC));
  out[1] = *((s32 *) (arg0 + 0x128));
  out[2] = (*((s32 *) (arg0 + 0x174))) >> 2;
  out[3] = *((s32 *) (arg0 + 0x1C0));
  for (i = 4; i < 0x18; i++)
  {
    out[i] = 0;
  }

  i = 1;
  ;
  if (((out[1] - out[0]) / 1000) != 0)
  {
    tab = *((char **) (D_800C02AE + 0x32F2));
    cur = arg0 + 0x4C;
    new_var = 0x1C0;
    do
    {
      new_var2 = out;
      a1 = *((u32 *) (cur + new_var));
      if (i >= 5)
      {
        {
          v = *((u16 *) (tab + 0x16));
          switch (v)
          {
            case 0:
              a1 -= a1 / 10;
              break;

            case 1:
              break;

            case 2:
              a1 += a1 / 10;
              break;

          }

        }
      }
      out[i + 4] = a1;
      cur += 0x4C;
      i++;
      q = (out[1] - new_var2[0]) / 1000;
    }
    while (((u32) ((out[1] - out[0]) / 1000)) >= i);
  }
  saved = out[0];
  t3[0] = 0;
  t3[2] = 0;
  t3[5] = 0x10;
  t3[1] = saved;
}
