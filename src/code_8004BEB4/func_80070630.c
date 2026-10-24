#include "common.h"

extern unsigned char D_800C7112;
extern int D_800C3508;
void *func_800592AC();
s32 func_800592F4();
s32 func_8005C0E8();
s32 func_8006E380();
s32 func_8008A0D8();
extern void *D_800A1468;
extern char D_800C02AE[];
void func_80070630(void)
{
  s32 var_s1;
  s8 var_s0;
  void *var_s2;
  s32 new_var;
  var_s2 = func_800592AC(1);
  new_var = func_8006E380();
  var_s0 = 0;
  if (new_var != 0)
  {
    var_s1 = 1;
    if ((D_800C7112 & 3) == (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE))))
    {
      var_s0 = 1;
      var_s1 = 0;
    }
  }
  else
  {
    var_s1 = 1;
  }
  func_8008A0D8(D_800C3508, 1, var_s0);
  *((s8 *) (((char *) var_s2) + 0x41)) = var_s0;
  func_8005C0E8(1, var_s1, *((s32 *) (((char *) D_800A1468) + 0x14)));
  var_s2 = func_800592AC(2);
  if ((*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x38))) != 0)
  {
    var_s0 = 1;
    var_s1 = 0;
  }
  else
  {
    var_s0 = 0;
    var_s1 = 1;
  }
  func_8008A0D8(D_800C3508, 2, var_s0);
  *((s8 *) (((char *) var_s2) + 0x41)) = var_s0;
  func_800592F4(2, ((u16) (*((u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0x20)))) >= 8U);
  func_8005C0E8(2, var_s1, *((s32 *) (((char *) D_800A1468) + 0x14)));
}
