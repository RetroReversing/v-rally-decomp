#include "common.h"

extern unsigned char D_800B6818;
extern int D_800C3508;
void *func_800592AC();
s32 func_800592F4();
s32 func_8005C0E8();
s32 func_8008A0D8();
extern void *D_800A1468;
extern u8 D_800A1700;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80070A34(void)
{
  s8 var_s0;
  void *temp_s1;
  void *temp_v1;
  s32 *new_var2;
  int new_var;
  temp_s1 = func_800592AC(2);
  new_var = 0;
  if ((D_800A1700 == 2) || ((var_s0 = 1, (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE))) == 2)))
  {
    D_800B6818 = 1U;
    new_var2 = (s32 *) (((char *) D_800A1468) + 0x14);
    temp_v1 = *((void **) (((char *) temp_s1) + 0));
    var_s0 = new_var;
    *((u16 *) (((char *) temp_v1) + 0xC)) -= 0x20;
    func_8005C0E8(2, 1, *new_var2);
  }
  func_800592F4(7, D_800B6818 == 1);
  *((s8 *) (((char *) temp_s1) + 0x41)) = var_s0;
  func_8008A0D8(D_800C3508, 7, var_s0);
}
