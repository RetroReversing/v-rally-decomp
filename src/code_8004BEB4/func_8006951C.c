#include "common.h"

s32 func_80068D9C();
extern void *D_800A1468;
extern char D_800A167C[];
extern char D_800A1684[];
extern char D_800C02AE[];
static inline char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

s32 func_8006951C(void)
{
  s32 temp_v0;
  int new_var;
  s32 var_a0;
  s8 temp_v1;
  u32 var_s0;
  void *temp_a0;
  var_s0 = 0x75834210;
  new_var = (*((s8 *) (inline_fn(D_800A1468) + 0x22A))) * 0x28;
  *((s32 *) (((char *) ((*((s32 *) (D_800C02AE + 0x32F2))) + new_var)) + 0x68)) = 0x75834210;
  temp_a0 = (*((s32 *) (D_800C02AE + 0x32F2))) + ((*((s8 *) (inline_fn(D_800A1468) + 0x22A))) * 0x28);
  *((u8 *) (((char *) temp_a0) + 0x48)) &= 0xEF;
  func_80068D9C(0x19, 0);
  var_a0 = 0;
  do
  {
    temp_v1 = var_s0 & 0xF;
    temp_v0 = var_a0 & 0xFF;
    var_a0 += 1;
    *(D_800A167C + temp_v0) = temp_v1;
    *(D_800A1684 + temp_v0) = temp_v1;
    var_s0 = var_s0 >> 4;
  }
  while (((u32) (var_a0 & 0xFF)) < 8U);
  return 0;
}
