#include "common.h"

extern int D_800C35A0;
s32 func_800592F4();
extern void *D_800A1468;
extern char D_800C02AE[];
s32 func_8006735C(void)
{
  u8 temp_v1;
  u8 var_v0;
  char *new_var;
  void *temp_a0;
  temp_a0 = D_800C35A0 + ((*((s8 *) (((char *) D_800A1468) + 0x22A))) * 0x28);
  temp_v1 = *((u8 *) (((char *) temp_a0) + 0x48));
  if (temp_v1 & 4)
  {
    var_v0 = temp_v1 & 0xFB;
  }
  else
  {
    var_v0 = temp_v1 | 4;
  }
  *((u8 *) (((char *) temp_a0) + 0x48)) = var_v0;
  new_var = ((char *) (D_800C35A0 + ((*((s8 *) (((char *) D_800A1468) + 0x22A))) * 0x28))) + 0x48;
  func_800592F4(0x1E, (((u8) (*((u8 *) new_var))) >> 2) & 1);
  return 0;
}
