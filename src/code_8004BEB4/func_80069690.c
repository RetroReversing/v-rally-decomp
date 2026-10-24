#include "common.h"

extern int D_800C35A0;
void *func_800592AC();
s32 func_80059618();
s32 func_800596F4();
s32 func_8006874C();
extern void *D_800A1468;
extern char D_800C02AE[];
void func_80069690(void)
{
  int new_var;
  u8 var_a1;
  u8 var_a2;
  u8 var_a3;
  void *temp_s0;
  void *temp_v0;
  temp_v0 = func_800592AC(0);
  temp_s0 = *((void **) (((char *) temp_v0) + 0x28));
  var_a1 = 0xDC;
  if ((*((u8 *) (((char *) temp_v0) + 0x42))) != 0)
  {
    var_a2 = 0xDC;
    var_a3 = 0xE;
  }
  else
  {
    var_a1 = *((u8 *) (((char *) temp_s0) + 0xB));
    var_a2 = *((u8 *) (((char *) temp_s0) + 0xC));
    var_a3 = *((u8 *) (((char *) temp_s0) + 0xD));
  }
  func_80059618(temp_s0, var_a1, var_a2, var_a3, 0xFF);
  func_800596F4(temp_s0, *((s16 *) (((char *) temp_s0) + 6)), *((s16 *) (((char *) temp_s0) + 8)), D_800C35A0 + (((*((s8 *) (((char *) D_800A1468) + 0x22A))) * 0x28) + (new_var = 0x44)));
  func_8006874C(*((s8 *) (((char *) D_800A1468) + 0x22A)));
}
