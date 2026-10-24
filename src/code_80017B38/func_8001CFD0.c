#include "common.h"

s32 func_8002B618();
s32 func_80098180();
extern char D_800A47B4[];
void func_8001CFD0(void *arg0)
{
  char pad[8];
  s32 new_var2;
  s32 *var_a1;
  s32 var_s0;
  s32 var_s3;
  s32 var_v0;
  s32 var_v1;
  s32 *new_var;
  u32 var_s1;
  void *var_a0;
  void *var_s2;
  var_s2 = arg0;
  var_v0 = *((s32 *) (((char *) var_s2) + 0x44));
  var_v0 = var_v0 < 4;
  if (var_v0 == 0)
  {
    var_a1 = &D_800A47B4;
    ;
    if (func_80098180(var_s2 + 0x98, &D_800A47B4) != 0)
    {
      new_var = (s32 *) (((char *) var_s2) + 0x44);
      var_v1 = *new_var;
      var_a1 = &D_800A47B4;
      var_s3 = var_v1;
      var_v0 = var_v1 - 4;
      var_s1 = 0;
      if (var_v0 != 0)
      {
        var_v0 = var_v1 * 4;
        var_v0 = var_s3 * 5;
        var_v0 = var_v1 * 0x14;
        var_v0 = var_v1 * 0x13;
        var_s3 = var_v1 * 0x4C;
        do
        {
          new_var2 = var_s3;
          var_s0 = 0xE4;
          do
          {
            ;
            var_a1 = var_s2 + var_s0;
            func_8002B618(var_s2 + new_var2, var_a1);
            var_v0 = *((s32 *) (((char *) var_s2) + 0x44));
            var_s1 += 1;
            var_v0 -= 4;
            var_v0 = (u32) var_v0;
            var_v0 = var_s1 < var_v0;
            var_s0 += 0x4C;
          }
          while (var_v0 != 0);
        }
        while (0);
      }
    }
  }
}
