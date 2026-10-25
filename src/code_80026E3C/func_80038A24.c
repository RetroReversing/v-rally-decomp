#include "common.h"

s32 func_8007EE9C();
s32 func_80086AD8();

void func_80038A24(void *arg0)
{
  s32 temp_s1;
  u8 var_s0;

  temp_s1 = *((s32 *) *((s32 *) ((char *) arg0 + 0x68)));
  var_s0 = 0;
  do
  {
    func_80086AD8(temp_s1 + var_s0 * 12, 0);
    var_s0++;
  }
  while (var_s0 < 6);
  func_8007EE9C(temp_s1);
}
