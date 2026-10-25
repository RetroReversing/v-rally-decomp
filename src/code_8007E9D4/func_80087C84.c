#include "common.h"

void *func_80087C84(void *arg0, u8 *arg1)
{
  u8 temp_v1;
  s32 temp_v0;
  s32 temp_a;

  temp_v1 = *arg1++;
  if (temp_v1 < 0x80)
  {
    *(s16 *)((u8 *)arg0 + 0xA4) = temp_v1;
  }
  else
  {
    temp_v0 = (temp_v1 & 0x7F) << 8;
    *(s16 *)((u8 *)arg0 + 0xA4) = temp_v0;
    temp_a = *arg1++;
    *(s16 *)((u8 *)arg0 + 0xA4) = temp_v0 + temp_a;
  }
  return arg1;
}
