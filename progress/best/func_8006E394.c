#define R D_800C35A0
#define H(p) (*(u16*)(p))
#define VH(p) (*(volatile u16*)(p))
#define W(p) (*(u32*)(p))
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern void func_80053C28(u8, u16);
extern u8 *D_800C35A0;
void func_8006E394(void)
{
  u8 used[4];
  u8 *s;
  u8 *new_var;
  int new_var3;
  u8 j;
  u8 i;
  u8 n;
  u8 base;
  u32 x;
  u8 *new_var2;
  u32 q;
  unsigned char v;
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
    H(R + 14) = (x >> 8) & 3;
    R[0x32] = (VH(s) >> 4) & 15;
    used[R[0x32]] = 1;
    H((R + (R[0x32] * 40)) + 0x4e) = D_800C02AE[0x701e] & 15;
    if (H(R + 14) >= 2)
    {
      R[0x33] = *((volatile u16 *) s) & 15;
      used[R[0x33]] = 1;
      H((R + (R[0x33] * 40)) + 0x4e) = D_800C02AE[0x701e] >> 4;
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

      R[0x33] = i;
      H((R + (R[0x33] * 40)) + 0x4e) = H(s) & 15;
      func_80053C28(R[0x33], H(s) & 15);
    }
    new_var2 = D_800AE850 + 0x7db8;
    for (i = 0; i < 4; i++)
    {
      if (!used[i])
      {
        used[i] = 1;
        break;
      }
    }

    R[0x34] = i;
    H((R + (R[0x34] * 40)) + 0x4e) = (*((volatile u16 *) (s + 2))) >> 12;
    func_80053C28(R[0x34], H(s + 2) >> 12);
    for (i = 0; i < 4; i++)
    {
      if (!used[i])
      {
        used[i] = 1;
        break;
      }
    }

    R[0x35] = i;
    H((R + (R[0x35] * 40)) + 0x4e) = (H(s + 2) >> 8) & 15;
    func_80053C28(R[0x35], (H(s + 2) >> 8) & 15);
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
    q = s[9];
    for (i = 0; i < n; i++)
    {
      if ((q & (1 << i)) == (1 << i))
      {
        H((D_800AE850 + 0x7dc0) + ((base + i) * 2)) = 1;
      }
      else
      {
        H((D_800AE850 + 0x7dc0) + ((base + i) * 2)) = 0;
      }
    }

    new_var = D_800AE850;
    W(new_var + 0x7db0) = 0;
    W(D_800AE850 + 0x7db4) = 0;
    W(new_var2) = 0;
    W(D_800AE850 + 0x7dbc) = 0;
    for (j = 0; j < 4; j++)
    {
      q = H((s + 10) + (j * 2));
      for (i = 0; i < n; i++)
      {
        new_var3 = 1;
        v = ((q & (1 << (i * 2))) == (new_var3 << (i * 2))) | (((q & (1 << ((i * 2) + 1))) == (1 << ((i * 2) + 1))) << new_var3);
        D_800AE850[(0x7dd8 + ((base + i) * 4)) + j] = v;
        switch (v)
        {
          case 0:
            W((D_800AE850 + 0x7db0) + (j * 4)) += 4;
            break;

          case 1:
            W((D_800AE850 + 0x7db0) + (j * 4)) += 2;
            break;

          case 2:
            W((D_800AE850 + 0x7db0) + (j * 4))++;
            break;

        }

      }

    }

    for (i = 0; i < 4; i++)
    {
      W((D_800AE850 + 0x7f18) + (i * 4)) = 0;
    }

    W(D_800AE850 + 0x7f18) = (s[3] + (s[4] << 8)) + (s[5] << 16);
    W(D_800AE850 + 0x7f1c) = (s[6] + (s[7] << 8)) + (s[8] << 16);
  }
}
