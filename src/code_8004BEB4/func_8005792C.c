#include "common.h"

extern u8 D_800A13B4[];
void func_80058E28();
void func_8005914C();
s32 func_80089F80();
void func_8005792C(void)
{
  u8 i;

  for (i = 0; i < 5; i++) {
    func_80089F80(D_800A13B4 + i * 0x24, func_80058E28, func_8005914C);
  }
}
