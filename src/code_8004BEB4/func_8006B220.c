#include "common.h"

s32 func_800592F4();
s32 func_8006204C();
extern void *D_800A1468;
extern void *D_800C35A0;
s32 func_8006B220(s32 arg0)
{
  s32 pad;
  char *temp_a2;
  char *temp_s0;
  int new_var;
  char *base;
  s16 temp_v0;
  s16 temp_a0;
  base = (char *) D_800C35A0;
  temp_s0 = base + ((((u8 *) (base + (*((s8 *) (((char *) D_800A1468) + 0x228)))))[0x32] * 0x28) + 0x44);
  temp_a2 = temp_s0 + ((func_8006204C(((u8 *) base)[0x1F], ((u8 *) base)[0x21], ((u8 *) base)[0x23]) & ((long long) 0xFF)) * 2);
  temp_v0 = *((s16 *) (temp_a2 + 0x1C));
  new_var = 0x1C;
  temp_a0 = temp_v0;
  if (temp_v0 < 0x14)
  {
    temp_a0 = temp_v0 + 0xA;
    *((s16 *) (temp_a2 + new_var)) = temp_a0;
    func_800592F4(arg0, (-((s16) (temp_a0 / 10))) + 2, temp_a2);
  }
  return 1;
}
