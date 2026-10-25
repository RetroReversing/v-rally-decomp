#include "common.h"

s32 func_8007EE9C();
extern char D_800C02AE[];

void func_8005060C(void *arg0)
{
  u8 var_s1;
  u8 var_s3;
  s32 var_v0;
  void *var_s0;
  void *var_s2;

  var_s2 = arg0;
  if (*(u16 *)((char *)*(void **)(D_800C02AE + 0x32F2) + 0x1E) == 0) {
    var_v0 = *(u8 *)((char *)var_s2 + 0x111);
  } else {
    var_v0 = 4;
  }
  var_v0 &= 0xFF;
  if (var_v0 != 0) {
    var_s1 = 0;
    var_s3 = var_v0;
    do {
      var_s0 = (char *)var_s2 + (var_s1 * 0x44);
      if (*(u16 *)((char *)var_s0 + 8) & 1) {
        if (*(s32 *)var_s0 != 0) {
          func_8007EE9C(*(s32 *)var_s0);
        }
        if (*(s32 *)((char *)var_s0 + 4) != 0) {
          func_8007EE9C(*(s32 *)((char *)var_s0 + 4));
        }
        *(u16 *)((char *)var_s0 + 8) = 0;
      }
      var_s1++;
    } while (var_s1 < var_s3);
  }
}
