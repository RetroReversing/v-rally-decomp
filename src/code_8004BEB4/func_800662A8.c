#include "common.h"

s32 func_80047F94();
s32 func_80053A78();
s32 func_8005A360();
s32 func_8005C198();
extern void *D_800A1468;
extern s8 D_800A16D4;
extern char D_800C02AE[];
extern s32 func_8006556C;
extern s32 func_80065860;
s32 func_800662A8(s32 arg0, s32 arg1)
{
  char *new_var;
  s16 *new_var2;
  if (D_800A1468)
  {
    func_8005C198();
    func_8005A360(arg0, arg1);
    D_800A16D4 = 2;
    new_var2 = (s16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x22);
    new_var = (char *) D_800A1468;
    *((s32 **) (new_var + 0x288)) = &func_8006556C;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_80065860;
    *new_var2 = 0;
    func_80047F94(*((void **) (D_800C02AE + 0x32F2)));
    func_80053A78();
    return 1;
  }
  else
  {
    func_8005C198();
    func_8005A360(arg0, arg1);
    D_800A16D4 = 2;
    new_var2 = (s16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x22);
    new_var = (char *) D_800A1468;
    *((s32 **) (new_var + 0x288)) = &func_8006556C;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_80065860;
    *new_var2 = 0;
    func_80047F94(*((void **) (D_800C02AE + 0x32F2)));
    func_80053A78();
    return 1;
  }
}
