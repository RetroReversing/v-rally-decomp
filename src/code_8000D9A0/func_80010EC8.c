#include "common.h"

extern u16 D_8009BEE4;
extern u32 D_800A18D0;
extern u8 D_800A16F4[];
extern u8 *D_800C35A0;
void func_80010EC8(u8 *arg0, u8 *arg1)
{
  u32 temp;
  u32 flag;
  u8 *obj;
  s32 limit;

  temp = *(u32 *)(arg0 + 0x30);
  flag = D_800A18D0 & 2;
  temp = temp + 1;
  *(u32 *)(arg0 + 0x30) = temp;
  limit = D_8009BEE4 - (flag == 0);
  if (!(temp < limit))
  {
    *(u32 *)(arg0 + 0x30) = 0;
  }
  obj = *(u8 **)(arg1 + 0x48);
  if (*(s32 *)(obj + 0x20) == 0)
  {
    D_800A16F4[*(D_800C35A0 + *(s32 *)obj + 0x32)] = *(u32 *)(arg0 + 0x30);
  }
}
