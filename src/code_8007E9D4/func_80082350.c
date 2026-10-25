#include "common.h"

s32 func_80082314();

u8 func_80082350(u8 *arg0, u8 *arg1)
{
  u8 *var_s2;
  u8 *var_s1;
  u8 var_s0;
  u8 var_a0;

  var_s2 = arg1;
  var_s1 = arg0;
  var_a0 = *var_s1;
  if (var_a0 != 0) {
    do {
      var_s0 = func_80082314(var_a0);
      if (var_s0 != (u8) func_80082314(*var_s2)) {
        return 0;
      }
      var_s1++;
      var_s2++;
      var_a0 = *var_s1;
    } while (var_a0 != 0);
  }
  return *var_s2 == 0;
}
