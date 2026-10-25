#include "common.h"

extern u16 D_800B5C58;
extern u16 D_800B5C68;
extern u16 D_800B5C5C;
extern s32 D_800B5C60;
void func_8000F1D4(s32, void *);

void func_8000F49C(s32 arg0)
{
  s32 flags;
  u16 temp_v0;
  u16 *var_a1;

  var_a1 = &D_800B5C58;
  flags = D_800B5C60;
  if (flags != 0) {
    *var_a1 = *var_a1 - 1;
    if (flags & 1) {
      temp_v0 = D_800B5C68 - D_800B5C5C;
      D_800B5C68 = temp_v0;
      if ((s16) temp_v0 < 0) {
        D_800B5C60 = 0;
        D_800B5C68 = 0;
        *var_a1 = D_800B5C5C;
      }
      func_8000F1D4(arg0, var_a1);
    } else if (flags & 2) {
      temp_v0 = D_800B5C68 + D_800B5C5C;
      D_800B5C68 = temp_v0;
      if ((s16) temp_v0 >= 0x100) {
        D_800B5C60 = 0;
        D_800B5C68 = 0xFF;
        *var_a1 = D_800B5C5C;
      }
      func_8000F1D4(arg0, var_a1);
    }
  }
}
