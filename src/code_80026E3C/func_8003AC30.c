#include "common.h"

s32 func_80099DF8();
extern u32 D_8009D540;
extern char D_800A4B30[];
void func_8003AC30(u32 arg0, char *arg1)
{
  s32 temp_v1;
  u32 temp_a0;
  u16 var_a2;
  u16 var_v0;
  int new_var;
  temp_v1 = arg0 / (D_8009D540 * 0x3C);
  temp_v1 &= 0xFFFF;
  new_var = temp_v1 != 0;
  temp_v1 = temp_v1 * 0x3C; temp_a0 = arg0 - (temp_v1 * D_8009D540);
  var_a2 = temp_a0 / ((u32) D_8009D540);
  var_v0 = ((u32) ((temp_a0 - ((var_a2 & 0xFFFF) * D_8009D540)) * 0x64)) / ((u32) D_8009D540);
  if (new_var)
  {
    var_a2 = 0x3B;
    var_v0 = 9;
  }
  func_80099DF8(arg1, &D_800A4B30, var_a2 & 0xFFFF, var_v0 & 0xFFFF);
}
