#include "common.h"

s32 func_800857C0();
s32 func_800858A4();
extern char D_800AE850[];

void func_8002FD68(void)
{
  s32 var_s4;
  s32 var_s5;
  u8 var_s3;
  u8 idx;
  s32 s1;
  s32 var_v1;

  var_s3 = 0;
  var_s5 = 1;
  var_s4 = (s32)(D_800AE850 + 0x2390);
  do
  {
    idx = var_s3;
    s1 = idx << 4;
    if (*((u8 *)(D_800AE850 + 0x239C + s1)) != func_800857C0(idx, 2))
    {
      *((u8 *)(D_800AE850 + 0x239D + s1)) = var_s5;
      *((s32 *)(D_800AE850 + 0x2394 + s1)) = 0;
    }
    if (*((s32 *)(D_800AE850 + 0x2394 + s1)) != 0)
    {
      var_v1 = s1 + var_s4;
      *((s16 *)(var_v1 + 2)) = *((u16 *)(D_800AE850 + 0x2392 + s1)) + 1;
      if (*((u8 *)(D_800AE850 + 0x2390 + s1)) <= *((u16 *)(D_800AE850 + 0x2392 + s1)))
      {
        *((s32 *)(D_800AE850 + 0x2394 + s1)) = 0;
        func_800858A4(idx, 2, 0);
      }
    }
    var_s3++;
  } while (var_s3 < 4);
}
