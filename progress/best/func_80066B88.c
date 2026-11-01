typedef struct 
{
  u8 x[4];
} Four;
extern Four D_800A56F0;
extern u8 *D_800C35A0;
void func_8006F0E0(u8);
void func_8006F4A8(u8);
void func_8006F75C(void);
static inline static static static u8 inline_fn(u8 *arg0, s8 arg1)
{
  return arg0[(s8) arg1];
}

void func_80066B88(void)
{
  u8 a[4];
  u8 b[4];
  s32 changed;
  s8 k;
  s8 new_var2;
  s8 i;
  s8 j;
  s8 idx;
  u8 *new_var;
  s32 n;
  s8 *p;
  u8 *q;
  *((Four *) a) = D_800A56F0;
  *((Four *) b) = D_800A56F0;
  changed = 0;
  k = 0;
  q = D_800C35A0 + 0x44;
  p = ((s8 *) D_800C35A0) + 0x32;
  do
  {
    new_var = b;
    i = 0;
    do
    {
      if ((idx = q[((s8) i) * 40]) < ((unsigned long) 91))
      {
        b[(s8) i] = 0;
      }
      if (1)
      {
        j = 0;
      }
      do
      {
        if (p[(s8) j] == ((s8) i))
        {
 do { a[p[(s8) j]] = 0; } while (0);
        }
        j++;
      }
      while (((s8) j) < 2);
      i++;
    }
    while (((s8) i) < 4);
    if (b[p[(s8) k]])
    {
      i = 0;
      for (; ((s8) i) < 4; i++)
      {
        if (!new_var[(s8) i])
        {
          continue;
        }
        if (!inline_fn(b, i))
        {
          break;
        }
        changed++;
        changed--;
      }

      n = (u8) i;
      idx = k;
      new_var2 = (s8) idx;
      if (i == 4)
      {
        s8 *x = p + new_var2;
        func_8006F4A8(*((u8 *) x));
        q[(*x) * 40] = 0x50;
        q[((*x) * 40) + 1] = 0x4C;
        q[((*x) * 40) + 2] = (*x) + 0x41;
        func_8006F0E0(*((u8 *) x));
        changed = 1;
      }
      else
      {
        i = 0;
        while ((((s8) i) < 4) && (p[(s8) i] != ((s8) n)))
        {
          i++;
        }

        {
          u8 t = p[new_var2];
          p[new_var2] = n;
          p[(s8) i] = t;
        }
      }
    }
    k++;
  }
  while (((s8) k) < 2);
  if (changed & 255)
  {
    func_8006F75C();
  }
}
