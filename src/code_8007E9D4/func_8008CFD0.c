#include "common.h"

extern s32 D_800A2540;
extern s32 D_800A2548;

s32 osPiGetCmdQueue(void)
{
  s32 temp_v1;

  temp_v1 = D_800A2540;
  if (temp_v1 == 0)
  {
    return 0;
  }
  return D_800A2548;
}
