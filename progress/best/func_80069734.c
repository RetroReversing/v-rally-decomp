typedef struct 
{
  u8 pad0[0x228];
  s8 cur;
  u8 pad229;
  s8 want;
  s8 b22B;
  u8 pad22C[0x245 - 0x22C];
  u8 b245;
  u8 pad246[0x24D - 0x246];
  u8 b24D;
  u8 b24E;
  u8 pad24F[0x288 - 0x24F];
  void (*f288)(void);
  void (*f28C)(void);
} State;
extern State *D_800A1468;
extern u8 *D_800C35A0;
void func_8005A360(s32, s32);
void func_80066E20(void);
void func_80066EBC(void);
s32 func_80069734(void)
{
  u8 used[4] = {0, 0, 0, 0};
  State *new_var;
  u8 old;
  u8 *new_var2;
  u8 i;
  func_8005A360(0, 0);
  {
    State *s = D_800A1468;
    s->b245 = 0;
    s->f288 = func_80066E20;
    s->f28C = func_80066EBC;
  }
  D_800A1468->b24D = 0;
  D_800A1468->b22B = -1;
  new_var = D_800A1468;
  new_var2 = D_800C35A0;
  old = *(new_var2 + new_var->cur + 0x32);
  if (old != new_var->want)
  {
    (D_800C35A0 + new_var->cur)[0x32] = new_var->want;
    i = 0;
    if (D_800C35A0[0x32] == D_800C35A0[0x33])
    {
      do
      {
        used[(D_800C35A0 + i)[0x32]] = 1;
        i++;
      }
      while (i < 4);
      for (i = 0; i < 4; i++)
      {
        if (used[i] == 0)
        {
          break;
        }
      }

      D_800C35A0[0x33] = i;
    }
    else
    {
      for (; i < 4; i++)
      {
        if ((i != D_800A1468->cur) && ((D_800C35A0 + i)[0x32] == D_800A1468->want))
        {
          break;
        }
      }

      (D_800C35A0 + i)[0x32] = old;
    }
  }
  new_var->b24E = 0;
  new_var->b245 = 0;
  return 0;
}

