#include "common.h"

s32 func_800526E4();
s32 func_80052BB0();
s32 func_800595EC();
s32 func_8007A24C();
extern void *D_800A1468;
extern u8 D_800A1700;
extern char D_800A5CE4[];
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 func_80070C34;
extern s32 func_8007159C;
s32 func_800708F4(s32 arg0, s32 arg1)
{
  u16 *new_var2;
  s32 *new_var;
  if (D_800A1700 == 1)
  {
    *((u8 *) (D_800AE850 + 0x7FC9)) = (u8) (((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)))) >= 8U);
    func_800526E4((D_800AE850 + 0x7FC9) - 0x219);
    *((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (((*((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2))) * 0x14) + (*((s32 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 0x10))))) + 8)))) + 4)))) + 0x2C)) = 7;
    func_8007A24C(arg0, arg1);
  }
  else
  {
    func_80052BB0();
    new_var2 = (u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20);
    new_var = (s32 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 0x10);
    *new_var2 = (u16) (((*((u8 *) (D_800AE850 + 0x7FC9))) != 0) * 8);
    *((s32 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (((*((s16 *) (((char *) (*((void **) (D_800C02AE + 0x325A)))) + 2))) * 0x14) + (*new_var))) + 8)))) + 4)))) + 0x2C)) = 3;
    func_800595EC(&D_800A5CE4);
    *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_80070C34;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_8007159C;
  }
  *((s8 *) (D_800C02AE + 0x7F50)) = (s8) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)));
  return 0;
}
