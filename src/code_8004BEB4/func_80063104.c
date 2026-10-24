#include "common.h"

s32 func_8005A360();
s32 func_8005C198();
s32 func_8007EE9C();
extern void *D_800A1468;
extern s32 D_800A14D0;
extern char D_800C02AE[];
extern s32 func_8007A29C;
extern s32 func_8007A9A8;
extern s32 func_8007AA94;
s32 func_80063104(int arg0, s32 arg1)
{
  char *new_var2;
  char *new_var;
  func_8005C198();
  if (D_800A14D0 != 0)
  {
    func_8007EE9C(D_800A14D0);
    D_800A14D0 = 0;
  }
  func_8005A360(arg0, arg1);
  new_var2 = (char *) D_800A1468;
  new_var = ((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xF;
  *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_8007A29C;
  new_var += 0;
  *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_8007A9A8;
  *((s32 **) (new_var2 + 0x290)) = &func_8007AA94;
  *((s8 *) (((char *) D_800A1468) + 0x228)) = (s8) ((*((u8 *) new_var)) - 1);
  return 0;
}
