#include "common.h"

extern char D_800A4C94[];
extern char D_800A4CA0[];
extern char D_800A4CAC[];
extern char D_800C02AE[];
extern int D_800C355C;
s32 func_8002B618();
s32 func_80050DD4();
void *func_8007EAA0();
s32 func_80097E30();
void func_800415EC(void)
{
  u32 i;
  char *base;
  base = D_800C02AE + 0x10332;
  func_80097E30(base, 0, 0x7C);
  func_8002B618(D_800A4C94, D_800A4CA0);
  for (i = 0; i < 10; i++)
  {
    if ((*((u16 *) ((base + 0x3E) + (i * 2)))) != 0)
    {
      *((void **) ((base + 0x54) + (i * 4))) = func_8007EAA0(1, (*((u16 *) ((base + 0x3E) + (i * 2)))) * 0x2C4);
      func_80097E30(*((void **) ((base + 0x54) + (i * 4))), 0, (*((u16 *) ((base + 0x3E) + (i * 2)))) * 0x2C4);
    }
  }

  func_8002B618(D_800A4C94, D_800A4CAC);
  D_800C355C = 0;
  func_80050DD4();
}
