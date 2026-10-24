#include "common.h"

s32 func_800595EC();
extern void *D_800A1468;
extern char D_800A56F4[];
extern char D_800C02AE[];
extern s32 func_80066E20;
extern s32 func_80066EBC;
s32 func_800677E8(void)
{
  char *new_var3;
  int new_var2;
  char *new_var4;
  u8 temp_v0;
  void *new_var;
  u8 temp_v0_2;
  new_var = D_800A1468 + 0x280;
  temp_v0 = *((u8 *) (((char *) D_800A1468) + 0x282));
  if (temp_v0 != 0)
  {
    if (1)
    {
    }
    new_var4 = ((char *) D_800A1468) + 0x281;
    temp_v0_2 = temp_v0 - 1;
    new_var2 = 0x41;
    *((u8 *) (((char *) D_800A1468) + 0x282)) = temp_v0_2;
    *((s8 *) new_var4) = (s8) ((*((u8 *) (((char *) (new_var + (temp_v0_2 & 0xFF))) + 3))) - new_var2);
  }
  else
  {
    *((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2)) = 0;
    func_800595EC(&D_800A56F4);
    *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_80066E20;
    new_var3 = ((char *) D_800A1468) + 0x28C;
    *((s32 **) new_var3) = &func_80066EBC;
  }
  return 0;
}
