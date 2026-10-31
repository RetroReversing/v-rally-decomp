#include "snapshot31_verified.h"

extern unsigned int func_8004D31C();
extern void func_8005A388(s32, s32);
extern void func_8006AE34(void);
extern u8 *D_800A1468;
extern u8 D_800A16D4;
extern u8 D_800C02AE[];
s32 func_8006B664(s32 arg0, s32 arg1)
{
  s8 *new_var3;
  u8 *new_var;
  s8 *header;
  u8 *state;
  u8 *rec;
  u8 *element;
  u8 *new_var4;
  s32 idx;
  s32 offset;
  void **new_var2;
  s32 mode;
  offset = 0;
  func_8004D31C();
  func_8005A388(arg0, arg1);
  header = D_800A1468;
  state = *((u8 **) (D_800C02AE + 0x325A));
  new_var3 = header;
  new_var4 = state;
  new_var = new_var3 + 0x288;
  new_var2 = (void **) new_var;
  *new_var2 = func_8006AE34;
  idx = *((s16 *) (new_var4 + 2));

  D_800A16D4 = 3;
  element = (*((u8 **) (new_var4 + 0x10))) - (-(4 * (idx * 5)));
  rec = *((u8 **) (D_800C02AE + 0x32F2));
  mode = *((u16 *) (rec + 0x1E));
  switch (mode)
  {
    case 0:
      offset = 25;
      break;

    case 1:
      if (1)
    {
    }

    case 2:
      if (1)
    {
    }

    case 3:

    case 4:
      offset = 15;
      break;

    case 5:
      offset = 38;
      break;

  }

  *((u8 *) (D_800A1468 + 0x228)) = element[0xE] - offset;
  return 1;
}
