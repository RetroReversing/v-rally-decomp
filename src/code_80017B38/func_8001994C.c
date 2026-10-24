#include "common.h"

s32 func_800154A8();
s32 func_800195AC();
extern s32 D_8009D4EC;
void *func_8001994C(void *arg0)
{
  s32 var_s0;
  int new_var2;
  s32 var_s1;
  int new_var;
  void *var_s2;
  void *var_s3;
  var_s2 = arg0;
  new_var2 = 0;
  new_var = 4;
  func_800154A8(arg0, 1, D_8009D4EC);
  var_s1 = *((s32 *) (((char *) var_s2) + new_var2));
  func_800154A8(var_s1, (s32) (*((u16 *) (((char *) var_s2) + new_var))), D_8009D4EC);
  var_s0 = new_var2;
  var_s3 = var_s2;
  if (((s32) (*((u16 *) (((char *) var_s2) + 4)))) > new_var2)
  {
    do
    {
      func_800195AC(var_s1);
      var_s0 += 1;
      var_s1 += 8;
    }
    while (var_s0 < ((s32) (*((u16 *) (((char *) var_s3) + 4)))));
  }
  return var_s2;
}
