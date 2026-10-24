#include "common.h"

volatile long func_80022F98(s32);
extern s32 D_800C7410;
void func_8002305C(void)
{
  s32 *var_s0;
  int new_var;
  s32 temp_a0;
  s32 var_s1;
  var_s1 = 0;
  var_s0 = &D_800C7410;
  do
  {
    temp_a0 = *var_s0;
    new_var = 4;
    new_var = 1;
    var_s0 += new_var;
    var_s1 += new_var;
    func_80022F98(temp_a0);
  }
  while (var_s1 == 0);
}
