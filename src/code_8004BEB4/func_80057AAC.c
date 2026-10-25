#include "common.h"

s32 func_8000C188();
s32 func_8007EE9C();
s32 func_80081B28();
extern void *D_800A1468;
void func_80057AAC(void)
{
  s32 var_s0;
  s32 var_s1;
  void *temp_a0;

  temp_a0 = D_800A1468;
  var_s1 = 0;
  if (*((u8 *)temp_a0 + 0x22C) != 0) {
    do {
      var_s0 = (var_s1 & 0xFF) << 2;
      func_8000C188(*(s32 *)((u8 *)temp_a0 + (var_s0 + 0xE4)));
      var_s1++;
      var_s0 += (s32)D_800A1468;
      func_80081B28(*(s32 *)(var_s0 + 0x134));
      temp_a0 = D_800A1468;
    } while ((u32)(u8)var_s1 < (u32)*((u8 *)temp_a0 + 0x22C));
  }
  func_8007EE9C(D_800A1468);
  D_800A1468 = NULL;
}
