#include "common.h"

s32 func_80005E3C();
void func_8000574C(void *arg0, s32 arg1, s32 arg2)
{
  s32 new_var;
  new_var = *((s32 *) (((char *) arg0) + 0x20));
  if ((arg1 != 0) & (arg2 != 0))
  {
    goto block_2;
  }
  *((s32 *) (((char *) arg0) + 0x20)) = arg1;
  goto block_4;
  block_2:
  func_80005E3C(new_var);

  *((s32 *) (((char *) arg0) + 0x20)) = 0;
  func_80005E3C(*((s32 *) (((char *) arg0) + 0x24)));
  *((s32 *) (((char *) arg0) + 0x24)) = 0;
  *((s32 *) (((char *) arg0) + 0x20)) = arg1;
  *((s32 *) (((char *) arg0) + 0x24)) = arg2;
  *((u16 *) (((char *) arg0) + 0x28)) |= 2;
  return;
  block_4:
  *((s32 *) (((char *) arg0) + 0x24)) = arg1;

  return;
}
