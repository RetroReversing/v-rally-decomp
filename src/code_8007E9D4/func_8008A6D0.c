#include "snapshot29_0433f7af8f6d.h"

extern u8 D_800A1C80;
extern volatile s32 D_A4500000;
extern s32 osVirtualToPhysical(s32);
extern s32 func_800914C0(void);
s32 func_8008A6D0(s32 arg0, s32 arg1)
{
  s32 addr = arg0;
  s32 ret;
  if (D_800A1C80 != 0)
  {
    addr -= 0x2000;
  }
  if (((arg0 + arg1) & 0x1FFF) == 0)
  {
    D_800A1C80 = 1; }
  else
  {
    D_800A1C80 = 0;
  }
  if (func_800914C0() == 0)
  {
    ret = osVirtualToPhysical(addr);
    *(volatile s32 *)0xA4500000 = ret;
    ret = 0;
    *((vs32 *) 0xA4500004) = arg1;
    return ret;
  }
  return -1;
}
