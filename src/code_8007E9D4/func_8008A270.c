#include "common.h"

void func_8008A270(void *arg0, s32 arg1, s32 arg2)
{
  int new_var;
  new_var = (*((s32 *) (((s8 *) arg0) + 0x10))) + (((arg1 & 0xFFFF) * 4) * 5);
  *((s32 *) (((s8 *) new_var) + 0x10)) = arg2;
}
