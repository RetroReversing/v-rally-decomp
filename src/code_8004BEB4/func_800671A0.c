#include "common.h"

extern int D_800C35A0;
s32 func_8005A360();
s32 func_8006F0E0();
s32 func_8006F75C();
extern void *D_800A1468;
extern char D_800C02AE[];
extern s32 func_80069648;
extern s32 func_80069690;
static inline int inline_fn(int arg0, s8 arg1)
{
  return arg0 + arg1;
}

s32 func_800671A0(s32 arg0, s32 arg1)
{
  void *new_var;
  void *new_var2;
  if ((*((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2))) == 5)
  {
    func_8006F0E0(*((u8 *) (((char *) inline_fn(D_800C35A0, *((s8 *) (((char *) D_800A1468) + 0x228)))) + 0x32)));
    func_8006F75C();
  }
  func_8005A360(arg0, arg1);
  new_var = D_800A1468;
  *((s8 *) (((char *) new_var) + 0x245)) = 0;
  new_var2 = D_800A1468;
  *((s32 **) (((char *) new_var) + 0x288)) = &func_80069648;
  *((s32 **) (((char *) new_var) + 0x28C)) = &func_80069690;
  *((s8 *) (((char *) new_var2) + 0x24D)) = 0;
  return 0;
}
