#include "common.h"

extern int D_800C81D4;
extern float D_800C35E4;
s32 func_80086B34();
s32 func_80086D34();
s32 func_80086D90();
void func_80046720(s32 arg0, s32 arg1, s32 arg2, s32 *arg3)
{
  f32 var_fs0;
  if (func_80086D34(D_800C81D4 + 0x1C8) != 0)
  {
    var_fs0 = (f32)(f64)(u32)*arg3;
    if (var_fs0 > 9e6f) var_fs0 = 9e6f;
    func_80086B34(D_800C81D4 + 0x1C8);
    func_80086D90(D_800C81D4 + 0x1C8, (s32)(D_800C35E4 * (1.0f - (var_fs0 * 1.1111111e-7f))));
  }
}
