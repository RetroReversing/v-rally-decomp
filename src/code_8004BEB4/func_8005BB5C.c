#include "common.h"

extern char D_800A5344[];
extern char D_800A5354[];
extern u8 *D_800A1468;
extern char D_800C02AE[];
void func_800980D0(u8 *, u8 *);
s32 func_80034FF0(u8 *, s32);
void func_80081540(u8 *);
void func_8005BB5C(void)
{
  u8 buf[16];
  u8 *b;
  u8 *ptr;
  u8 *src;
  u8 *new_var;
  u8 k;
  u8 i;
  func_80081540(D_800A5344);
  i = 0;
  b = buf;
  do
  {
    ptr = *((u8 **) (D_800C02AE + 0x32F2));
    ptr = ptr + ((ptr + i)[0x32] * 0x28);
    src = (*((u8 **) (D_800C02AE + 0x103AA))) + ((*((u16 *) (ptr + 0x4E))) * 0x2C4);
    for (k = 0; k < 5; k++)
    {
      b[k] = src[k];
    }

    b[k] = 0;
    func_800980D0(b, D_800A5354);
    *((s32 *) (((new_var = D_800A1468) + (i * 4)) + 0x184)) = func_80034FF0(b, 0);
    i++;
  }
  while (i < 4);
}
