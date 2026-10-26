#include "common.h"

s32 func_8008BD90();
s32 func_8008BDB0();
extern char D_800C02AE[];
void osSetEventMesg(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_a0;
  void *temp_s0;
  temp_a0 = func_8008BD90();
  temp_s0 = (arg0 * 8) + (D_800C02AE + 0x75FA);
  *((s32 *) (((char *) temp_s0) + 0)) = arg1;
  *((s32 *) (((char *) temp_s0) + 4)) = arg2;
  func_8008BDB0(temp_a0);
}
