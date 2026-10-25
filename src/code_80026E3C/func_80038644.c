#include "common.h"

s32 func_80098180();
extern char D_800A4AE0[];
extern char D_800A4AE8[];
extern char D_800A4AF0[];
extern char D_800C02AE[];

void func_80038644(char *arg0)
{
  char *temp_s0;
  s8 var_v0;

  temp_s0 = arg0 + 0x4C;
  if (func_80098180(temp_s0, D_800A4AE0) == 0)
  {
    var_v0 = 0x18;
  }
  else if (func_80098180(temp_s0, D_800A4AE8) == 0)
  {
    var_v0 = 0x19;
  }
  else if (func_80098180(temp_s0, D_800A4AF0) == 0)
  {
    var_v0 = 0x1A;
  }
  else
  {
    return;
  }
  D_800C02AE[0x331A] = var_v0;
}
