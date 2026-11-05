#define H(p) (*(u16*)(p))
#define VH(p) (*(volatile u16*)(p))
#define R D_800C35A0
typedef struct 
{
  u16 v;
  u8 pad[38];
} Ent;
typedef struct 
{
  u8 pad0[0xe];
  u16 mode;
  u8 pad10[0x22];
  u8 slot[4];
  u8 pad36[0x18];
  Ent e[4];
} RS;
typedef struct 
{
  s32 cnt[4];
  u16 flag[12];
  u8 map[12][4];
} Blk;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern Blk D_800B6600;
extern s32 D_800B6768[4];
extern void func_80053C28(u8, u16);
extern RS *D_800C35A0;
void func_8006E394(void)
{
  u8 used[4];
  u16 m;
  unsigned int new_var2;
  u8 *s;
  u8 j;
  u8 i;
  u8 n;
  u8 base;
  u8 *new_var;
  u32 x;
  u16 q;
  u8 v;
  int b;
  for (i = 0; i < 4; i++)
  {
    used[i] = 0;
  }

  s = D_800C02AE + 0x6E64;
  x = H(s);
  D_800AE850[0x7FCA] = (x >> 14) & 1;
  if (D_800AE850[0x7FCA])
  {
    D_800AE850[0x7FC8] = (x >> 13) & 1;
    D_800AE850[0x7FC9] = x >> 15;
    R->mode = (x >> 8) & 3;
    R->slot[0] = (VH(s) >> 4) & 15;
    used[R->slot[0]] = 1;
    R->e[R->slot[0]].v = D_800C02AE[0x701e] & 15;
    if (R->mode >= 2)
    {
      n = *((volatile u16 *) s);
      R->slot[1] = n & 15;
      used[R->slot[1]] = 1;
      R->e[R->slot[1]].v = D_800C02AE[0x701e] >> 4;
    }
    else
    {
      for (i = 0; i < 4; i++)
      {
        if (!used[i])
        {
          used[i] = 1;
          break;
        }
      }

      new_var2 = 1;
      R->slot[new_var2] = i;
      R->e[R->slot[1]].v = H(s) & 15;
      func_80053C28(R->slot[1], H(s) & 15);
    }
    for (i = 0; i < 4; i++)
    {
      if (!used[i])
      {
        used[i] = 1;
        break;
      }
    }

    R->slot[2] = i;
    R->e[R->slot[2]].v = (*((volatile u16 *) (s + 2))) >> 12;
    func_80053C28(R->slot[2], H(s + 2) >> 12);
    for (i = 0; i < 4; i++)
    {
      if (!used[i])
      {
        used[i] = 1;
        break;
      }
    }

    R->slot[3] = i;
    R->e[R->slot[3]].v = (H(s + 2) >> 8) & 15;
    func_80053C28(R->slot[3], (H(s + 2) >> 8) & 15);
    if (D_800AE850[0x7fc9])
    {
      n = 4;
      base = 8;
    }
    else
    {
      do
      {
        n = 8;
        base = 0;
      }
      while (0);
    }
    m = s[9];
    for (i = 0; i < n; i++)
    {
      do
      {
        if ((m & (1 << i)) == (1 << i))
        {
          D_800B6600.flag[base + i] = 1;
        }
        else
        {
          D_800B6600.flag[base + i] = 0;
        }
      }
      while (0);
    }

    D_800B6600.cnt[0] = 0;
    D_800B6600.cnt[1] = 0;
    D_800B6600.cnt[2] = 0;
    D_800B6600.cnt[3] = 0;
    for (j = 0; j < 4; j++)
    {
      q = H((s + 10) + (j * 2));
      for (i = 0; i < n; i++)
      {
        b = base + i;
        do
        {
          do
          {
            {
              int m0 = 1 << (i * 2);
              int m1 = 1 << ((i * 2) + 1);
              int b0 = (q & ((u16) m0)) == ((u16) m0);
              int b1 = (q & ((u16) m1)) == ((u16) m1);
              v = b0 | (b1 << 1);
            }
          }
          while (0);
        }
        while (0);
        D_800B6600.map[b][j] = v;
        new_var = &D_800AE850[0x7DB0 + (j * 4)];
        switch (v)
        {
          case 0:
            *((s32 *) new_var) += 4;
            break;

          case 1:
            *((s32 *) new_var) += 2;
            break;

          case 2:
            *((s32 *) new_var) += 1;
            break;

        }

      }

    }

    for (i = 0; i < 4; i++)
    {
      D_800B6768[i] = 0;
    }

    D_800B6768[0] = (s[3] + (s[4] << 8)) + (s[5] << 16);
    D_800B6768[1] = (s[6] + (s[7] << 8)) + (s[8] << 16);
  }
}

