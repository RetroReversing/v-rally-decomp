#define H(p) (*(u16*)(p))
#define R D_800C35A0
typedef struct 
{
  u16 f15 : 1;
  u16 f14 : 1;
  u16 f13 : 1;
  u16 pad : 3;
  u16 f8 : 2;
  u16 f4 : 4;
  u16 f0 : 4;
  u16 g12 : 4;
  u16 g8 : 4;
  u8 b3;
  u8 b4;
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 b9;
  s16 sums[4];
  u8 pad12[0x1BA - 0x12];
  s8 code;
} Packet;
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
extern void func_80053C28(s32, s32);
extern RS *D_800C35A0;
static __inline__ int inline_fn(u8 arg0)
{
  return 0x7DB0 + (arg0 * 4);
}

void func_8006E394(void)
{
  u8 used[4];
  u16 m;
  Packet *p;
  u8 j;
  u8 i;
  u8 n;
  u8 base;
  u8 *new_var;
  u16 q;
  u8 v;
  int b;
  for (i = 0; i < 4; i++)
  {
    used[i] = 0;
  }

  p = (Packet *) (D_800C02AE + 0x6e64);
  D_800AE850[0x7FCA] = p->f14;
  if (D_800AE850[0x7FCA])
  {
    D_800AE850[0x7FC8] = p->f13;
    D_800AE850[0x7FC9] = p->f15;
    R->mode = p->f8;
    R->slot[0] = p->f4;
    used[R->slot[0]] = 1;
    R->e[R->slot[0]].v = D_800C02AE[0x701e] & 15;
    if (R->mode >= 2)
    {
      R->slot[1] = p->f0;
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

      R->slot[1] = i;
      R->e[R->slot[1]].v = p->f0;
      func_80053C28(R->slot[1], p->f0);
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
    R->e[R->slot[2]].v = p->g12;
    func_80053C28(R->slot[2], p->g12);
    for (i = 0; i < 4; i++)
    {
      if (!used[i])
      {
        used[i] = 1;
        break;
      }
    }

    R->slot[3] = i;
    R->e[R->slot[3]].v = p->g8;
    func_80053C28(R->slot[3], p->g8);
    if (D_800AE850[0x7fc9])
    {
      n = 4;
      base = 8;
    }
    else
    {
      n = 8;
      base = 0;
    }
    m = ((u8 *) p)[9];
    for (i = 0; i < n; i++)
    {
      do
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
      while (0);
    }

    D_800B6600.cnt[0] = 0;
    D_800B6600.cnt[1] = 0;
    D_800B6600.cnt[2] = 0;
    D_800B6600.cnt[3] = 0;
    for (j = 0; j < 4; j++)
    {
      q = H((((u8 *) p) + 10) + (j * 2));
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
        new_var = &D_800AE850[inline_fn(j)];
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

    D_800B6768[0] = (((u8 *) p)[3] + (((u8 *) p)[4] << 8)) + (((u8 *) p)[5] << 16);
    D_800B6768[1] = (((u8 *) p)[6] + (((u8 *) p)[7] << 8)) + (((u8 *) p)[8] << 16);
  }
}

