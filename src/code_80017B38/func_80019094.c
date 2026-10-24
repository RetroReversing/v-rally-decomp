#include "common.h"

s32 func_800154A8();
extern s32 D_8009D4EC;
void func_80019094(void *arg0)
{
  s32 temp_a0;
  *((s32 *) (((char *) arg0) + 0xC)) += D_8009D4EC;
  temp_a0 = (*((s32 *) (((char *) arg0) + 0x14))) + D_8009D4EC;
  *((s32 *) (((char *) arg0) + 0x14)) = temp_a0;
  func_800154A8(temp_a0, *((u16 *) (((char *) arg0) + 0x10)), D_8009D4EC);
}
