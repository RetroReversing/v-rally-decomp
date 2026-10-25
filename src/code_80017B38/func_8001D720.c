#include "common.h"

extern int D_800AE868;
void func_8001D720(void *arg0)
{
  s32 var_a2;
  s32 temp_a0;
  u8 temp_a1;
  char *temp_a3;

  temp_a3 = arg0;
  var_a2 = 1;
  do
  {
    var_a2++;
  }
  while ((u32) (var_a2 & 0xFF) < 0x11U);
  if (D_800AE868 != 0)
  {
    var_a2 = 0;
    do
    {
      temp_a0 = D_800AE868;
      temp_a1 = var_a2 & 0xFF;
      *((s8 *) (temp_a0 + temp_a1 + 0x40)) = *((s32 *) (temp_a3 + temp_a1 * 0x130 + 0x90));
      *((s8 *) (D_800AE868 + temp_a1 + 0x44)) = *((s32 *) (temp_a3 + temp_a1 * 0x130 + 0xDC));
      *((s8 *) (D_800AE868 + temp_a1 + 0x48)) = *((s32 *) (temp_a3 + temp_a1 * 0x130 + 0x128));
      *((s8 *) (D_800AE868 + temp_a1 + 0x4C)) = *((s32 *) (temp_a3 + temp_a1 * 0x130 + 0x174));
      var_a2++;
    }
    while ((u32) (var_a2 & 0xFF) < 4U);
  }
}
