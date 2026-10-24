#include "common.h"

extern unsigned short D_800D0630;
s32 func_80035438();
extern s32 D_800A1468;
extern char D_800C02AE[];
void func_80061EAC(void)
{
  s32 temp_a0;
  s32 temp_s1;
  s32 var_s0;
  var_s0 = 0;
  if (D_800D0630 != 0)
  {
    do
    {
      temp_s1 = (var_s0 & 0xFF) * 4;
      temp_a0 = *((s32 *) (((char *) (temp_s1 + D_800A1468)) + 0x194));
      if ((*((s32 *) (((char *) (((var_s0 & 0xFF) * 4) + D_800A1468)) + 0x194))) != 0)
      {
        func_80035438(temp_a0);
      }
      *((s32 *) (((char *) (((var_s0 & 0xFF) * 4) + D_800A1468)) + 0x194)) = 0;
      var_s0 += 1;
    }
    while (((u32) (var_s0 & 0xFF)) < ((u16) D_800D0630));
  }
}
