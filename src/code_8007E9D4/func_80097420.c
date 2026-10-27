#include "common.h"

extern s8 D_800A3B34;
extern u8 D_800C8130;
extern s32 func_80090DC0(s32, void *);
extern s32 __osPfsRequestOneChannel(s32);
extern s32 __osPfsGetOneChannelData(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
s32 func_80097420(s32 arg0, s32 arg1)
{
  int new_var;
  s32 sp10[2];
  s32 sp18[2];
  s32 temp_s0;
  void *temp_s1;
  new_var = 250;
  D_800A3B34 = new_var;
  __osPfsRequestOneChannel(arg1);
  temp_s1 = &D_800C8130;
  func_80090DC0(1, temp_s1);
  osRecvMesg(arg0, sp18, 1);
  temp_s0 = func_80090DC0(0, temp_s1);
  osRecvMesg(arg0, sp18, 1);
  __osPfsGetOneChannelData(arg1, sp10);
  if ((((u8 *) sp10)[2] & 1) && (((u8 *) sp10)[2] & 2))
  {
    return 2;
  }
  if ((((u16 *) sp10)[1] & 0x1ff) != 0x100)
  {
    return 1;
  }
  if (((u8 *) sp10)[2] & 4)
  {
    return 4;
  }
  return temp_s0;
}
