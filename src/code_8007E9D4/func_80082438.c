#include "common.h"

extern int D_800B7310;
extern int D_800B7318;
extern int D_800B7320;
extern unsigned short D_800C336A;
extern unsigned short D_800C3368;
extern int D_800C3354;
extern int D_800C333C;
extern int D_800C3340;
extern void * volatile D_800B7334;
s32 func_80098290();

char *func_80082438(s32 arg0)
{
  s32 temp_v1;
  char *temp_s0;
  temp_v1 = D_800B7310;
  D_800B7310 = temp_v1 + 1;
  temp_s0 = (char *)D_800B7318 + temp_v1 * 0x2C;
  func_80098290(temp_s0, arg0);
  *(s32 *)(temp_s0 + 0x10) = D_800B7320;
  *(s32 *)(temp_s0 + 0x14) = *((s32 *)D_800B7334 + 1);
  *(u16 *)(temp_s0 + 0x1A) = D_800C336A;
  *(u16 *)(temp_s0 + 0x18) = D_800C3368;
  *(s32 *)(temp_s0 + 0x1C) = D_800C3354;
  *(s32 *)(temp_s0 + 0x28) = D_800C333C;
  *(s32 *)(temp_s0 + 0x24) = D_800C3340;
  *(s32 *)(temp_s0 + 0x20) = *(s32 *)D_800B7334;
  return temp_s0;
}
