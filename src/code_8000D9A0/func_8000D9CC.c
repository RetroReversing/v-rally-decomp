#include "common.h"

extern int D_800AFA6C;
extern int D_800B4144;
extern int D_800C7308;
extern int D_800B56C0;
s32 func_80005890();
s32 func_8007F4E4();
s32 func_8007FB3C();
extern s32 D_8009B6E0;
extern s32 *D_8009B6E4;
extern char D_800AE850[];
extern char D_800C02AE[];
extern s32 *D_800C80C0;
extern s32 func_8000D9A0;
extern s32 func_8000DFB0;
s32 func_8000D9CC(void)
{
  s32 *temp_v1;
  s32 temp_v0;
  s32 flag;
  s32 var_v0;
  temp_v1 = D_800C80C0;
  D_800C80C0 = (s32 *) &func_8000D9A0;
  D_8009B6E4 = temp_v1;
  flag = func_80005890() & 0xFF;
  if (flag != 0)
  {
    D_800AFA6C = 0;
    D_800B4144 = func_8007F4E4(4, 0, 1);
    temp_v0 = func_8007F4E4(6, 0, 1);
    D_800C7308 = temp_v0;
    D_800B56C0 = func_8007FB3C(&func_8000DFB0, 0x400, 0x74, temp_v0);
  }
  var_v0 = 0;
  if (flag != 0)
  {
    var_v0 = D_8009B6E0 != 0;
  }
  return var_v0;
}
