#include "common.h"

extern void func_80035438();
extern s32 func_800803C0();
s32 func_80047DD0(s32 arg0, void **arg1)
{
  void **temp_s0;
  temp_s0 = *arg1;
  while (((arg0 & 0xFF) != 0) & (temp_s0 != 0))
  {
    arg0--;
    temp_s0 = *((void ***) (((char *) temp_s0) + 4));
  }

  if (((arg0 & 0xFF) != 0) || (temp_s0 == 0))
  {
    return 0;
  }
  func_80035438(*((void **) (((char *) temp_s0) + 0xC)));
  func_800803C0(temp_s0, arg1);
  return 1;
}
