#include "common.h"

typedef struct S2
{
  u8 f0;
  u8 f1;
  u8 f2;
  u8 f3;
  u8 f4;
  u8 f5;
} S2;
typedef struct S48
{
  u8 pad[0x2C];
  s32 f2C;
} S48;
typedef struct S1
{
  u8 pad[0x48];
  S48 *p48;
} S1;
extern u8 D_800A17F0[];
extern u8 D_800C02AE[];
extern u8 D_800AE850[];
s32 func_80084DD4(s32);
void func_80027E8C(S1 *, s32, S2 *);
void func_800280AC(S1 *, S2 *);
void func_800280EC(S1 *, S2 *);
void func_800347A4(S1 *, S2 *);
void func_80043150(S1 *, S2 *);
void func_800437B8(S1 *, S2 *);
void func_80043A78(S1 *, S2 *);
void func_8007B204(S1 *);
s32 func_80077724(void);
void func_80077214(S1 *, S2 *);
void func_80097E30(S2 *, s32, s32);
void func_80028158(S1 *arg0, s32 arg1, S2 *arg2, s32 arg3)
{
  unsigned short new_var;
  switch (arg3)
  {
    case 0:
      if (func_80084DD4(arg1 & 0xFF) != 0)
    {
      func_80027E8C(arg0, arg1, arg2);
    }
    else
    {
      arg2->f5 = 0;
      arg2->f4 = 0;
      arg2->f0 = 0;
      arg2->f1 = 0x10;
    }
      return;

    case 1:
      new_var = 0x80BE;
      func_800280AC(arg0, arg2);
      if (D_800C02AE[new_var] == 1)
    {
      D_800C02AE[new_var] = 0;
      func_8007B204(arg0);
    }
      return;

    case 2:
      func_800347A4(arg0, arg2);
      return;

    case 3:
      func_800437B8(arg0, arg2);
      return;

    case 4:
      func_80043A78(arg0, arg2);
      return;

    case 5:
      func_80043150(arg0, arg2);
      return;

    case 6:
      func_800280EC(arg0, arg2);
      return;

    case 7:

    case 8:

    case 9:

    case 10:

    case 11:
      break;

    default:
      return;

  }

  new_var = D_800A17F0[0] == 0;
  if (new_var)
  {
    if ((arg0->p48->f2C == D_800C02AE[0x7CF3]) && (*((s32 *) (D_800AE850 + 0x121C))))
    {
      if (func_80077724() & 0xFF)
      {
        func_80077214(arg0, arg2);
      }
      else
      {
        func_80097E30(arg2, 0, 8);
        arg2->f3 |= 0x10;
      }
    }
  }
}
