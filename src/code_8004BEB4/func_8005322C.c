#include "snapshot31_verified.h"

#define H(p,o) (*(u16 *)((u8 *)(p)+(o)))
#define M D_800C35A0
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
extern u8 *D_800D0634[];
void func_800529F0(void *, s32, s32);
void func_80052FA0(void);
void func_800783A8(void);
extern u8 *D_800C35A0;
void func_8005322C(void)
{
  u8 *m;
  u8 *new_var3;
  u8 *row;
  u8 **new_var5;
  u16 a;
  s32 *new_var2;
  u8 *new_var4;
  u8 *new_var;
  u16 b;
  u16 c;
  s32 off;
  m = M;
  c = H(m, 0x22);
  new_var3 = D_800AE850 + 0x7db0;
  a = H(m, 0x1e);
  new_var5 = &D_800D0634[a];
  b = H(m, 0x20);
  c++;
  off = b * 2;
  H(m, 0x22) = c;
  row = (*new_var5) + (b * 0x2c4);
  if (c == H(row, 0x14))
  {
    *((s16 *) ((new_var3 + off) + 0x10)) = 1;
    new_var = row;
    H(row, 0x10) |= 2;
    func_800529F0(new_var, c, off);
    func_80052FA0();
    func_800783A8();
    m = M;
    new_var2 = m;
    D_800C02AE[0x7f4f] = 5;
    D_800C02AE[0x7f51] = H(new_var2, 0xe);
    D_800C02AE[0x7f50] = H(new_var2, 0x20);
    b = H(new_var2, 0x20);
    H(new_var2, 0x1e) = 8;
    do
    {
      if (b < 8)
      {
        H(new_var2, 0x22) = b;
      }
      else
      {
        switch (b)
        {
          case 8:
            H(new_var2, 0x22) = 0;
            break;

          case 9:
            H(new_var2, 0x22) = 3;
            break;

          case 10:
            H(new_var2, 0x22) = 5;
            break;

          case 11:
            H(new_var2, 0x22) = 6;
            break;

        }

      }
    }
    while (0);
    new_var4 = D_800AE850 + 0x8030;
    new_var2 = (s32 *) new_var4;
    *new_var2 = 6;
    H(M, 0x20) = 0;
  }
}
