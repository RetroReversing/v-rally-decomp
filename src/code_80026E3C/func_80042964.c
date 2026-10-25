#include "common.h"

s32 func_8008E118();
s32 func_8008E13C();
extern s32 D_8009D530;
void func_80042964(u8 *arg0, u8 *arg1)
{
  s32 temp_s0;
  s32 temp_v0;
  u8 *new_var;
  s32 temp_v1;
  s32 temp_a3;
  u32 var_a0;
  u32 var_a1;
  s32 var_a2;
  u8 *var_v1;
  temp_s0 = ((s32) arg0) + 0x4C;
  temp_v0 = func_8008E118(temp_s0);
 do { func_8008E13C(arg1, temp_s0, temp_v0); var_a1 = 0; } while (0);
  temp_a3 = D_8009D530;
  var_a2 = 0x2C;
  do
  {
    var_a0 = 0;
    var_v1 = arg1 + var_a2;
    do
    {
      *((s32 *) var_v1) = temp_a3;
      var_a0 += 1;
      var_v1 += 0x10;
    }
    while (var_a0 < 3U);
    var_a1 += 1;
    var_a2 += 0x40;
  }
  while (var_a1 < 8U);
  temp_v1 = *((s32 *) (arg0 + 0xDC));
  if (temp_v1 == 1)
  {
    *((u16 *) (arg1 + 0x10)) |= 8;
  }
  if (temp_v1 == 2)
  {
    *((u16 *) (arg1 + 0x10)) |= 0x18;
  }
  new_var = arg0 + 0x174;
  *((s16 *) (arg1 + 0x16)) = *((s32 *) (arg0 + 0x128));
  *((s16 *) (arg1 + 0x14)) = *((s32 *) new_var);
}
