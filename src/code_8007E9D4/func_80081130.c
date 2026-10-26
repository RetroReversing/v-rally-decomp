#include "common.h"

s32 func_8007F73C();
s32 func_8008BDD0();
s32 osPiStartDma();
s32 osRecvMesg();
s32 osSendMesg();
extern char D_800AE850[];
extern char D_800C02AE[];
void func_80081130(void)
{
  void *sp20;
  s32 var_s1;
  void *var_s0;
  var_s1 = -8;
  var_s0 = D_800AE850 + 0x65B8;
  var_s1 = ~7;
  loop_1:
  osRecvMesg(D_800C02AE + 0x768A, &sp20, 1);

  func_8008BDD0(*((s32 *) (((char *) sp20) + 4)), *((s32 *) (((char *) sp20) + 8)));
  osPiStartDma(sp20 + 0xC, 0, 0, *((s32 *) (((char *) sp20) + 0)), *((s32 *) (((char *) sp20) + 4)), ((*((s32 *) (((char *) sp20) + 8))) + 7) & var_s1, var_s0);
  func_8007F73C(0x22, 1);
  osSendMesg(sp20 + 0x24, sp20 + 0x3C, 1);
  goto loop_1;
}
