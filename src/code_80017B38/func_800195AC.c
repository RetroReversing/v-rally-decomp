#include "common.h"

s32 func_800192D0();
void func_800195AC(void *arg0)
{
  char pad[8];
  s32 var_s0;
  s32 new_var;
  s32 var_s1;
  new_var = (s32) (*((u16 *) (((char *) arg0) + 4)));
  var_s1 = *((s32 *) (((char *) arg0) + 0));
  var_s0 = 0;
  if (new_var > 0)
  {
    do
    {
      func_800192D0(var_s1);
      var_s0 += 1;
      var_s1 += 0x24;
    }
    while (var_s0 < ((s32) (*((u16 *) (((char *) arg0) + 4)))));
  }
}
