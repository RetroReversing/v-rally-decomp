#include "common.h"

extern int D_800B0BCC;
s32 func_800520D4();
s32 func_80098400();
extern char D_800A5010[];
extern char D_800A5018[];
extern char D_800AE850[];
void func_800522B0(s32 arg0)
{
  char pad[8];
  s32 temp_a1;
  s32 var_s0;
  s32 var_s1;
  s32 var_s2;
  var_s2 = 0;
  var_s0 = 0;
  if (arg0 > 0)
  {
    var_s1 = 0;
    do
    {
      if ((func_80098400(D_800B0BCC + var_s1, &D_800A5010, 4) == 0) || (func_80098400(D_800B0BCC + var_s1, &D_800A5018, 4) == 0))
      {
        temp_a1 = var_s2 & 0xFFFF;
        var_s2 += 1;
 do { func_800520D4(var_s0 & 0xFFFF, temp_a1); } while (0);
      }
      var_s0 += 1;
      var_s1 += 0x14;
    }
    while (var_s0 < arg0);
  }
}
