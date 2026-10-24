#include "common.h"

extern int D_800C35A0;
s32 func_800592F4();
extern void *D_800A1468;
extern char D_800C02AE[];
s32 func_800672D0(void)
{
  u8 temp_v1;
  u8 var_v0;
  void *temp_a0;
  u8 *new_var;
  temp_a0 = D_800C35A0 + ((*((s8 *) (((char *) D_800A1468) + 0x22A))) * 0x28);
  temp_v1 = *((u8 *) (((char *) temp_a0) + 0x48));
  if (temp_v1 & 2)
  {
    var_v0 = temp_v1 & 0xFD;
  }
  else
  {
    var_v0 = temp_v1 | 2;
  }
  *((u8 *) (((char *) temp_a0) + 0x48)) = var_v0;
  new_var = &(*((u8 *) (((char *) (D_800C35A0 + ((*((s8 *) (((char *) D_800A1468) + 0x22A))) * 0x28))) + 0x48)));
  func_800592F4(0x1D, (((u8) (*new_var)) >> 1) & 1);
  return 0;
}
