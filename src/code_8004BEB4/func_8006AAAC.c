#include "common.h"

s32 func_80005C48(s32);
extern s32 D_8009B5A4;
void func_8006AAAC(u16 *arg0, s16 *arg1)
{
  s16 buf[8];
  s32 var_t0;
  s32 var_t1;
  s32 var_a1;
  s32 var_a2;
  s32 var_a3;
  u16 val;
  s32 off;
  var_t1 = func_80005C48(D_8009B5A4);
  var_a2 = 0;
  if (arg1[3] > 0)
  {
    var_t0 = 0;
    do
    {
      var_a1 = 0;
      if (arg1[2] > 0)
      {
        var_a3 = var_t0;
        do
        {
          off = (((arg1[1] + var_a2) * 0x140) + arg1[0] + var_a1) * 2;
          val = *(u16 *)(off + (u8 *)arg0);
          *((u16 *) (var_t1 + ((var_a3 + var_a1) * 2))) = *(u16 *)(off + (u8 *)arg0);
          var_a1 += 1;
        }
        while (var_a1 < arg1[2]);
      }
      var_a2 += 1;
      var_t0 += 0x140;
    }
    while (var_a2 < arg1[3]);
  }
}
