#include "common.h"

void func_80008C58(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  unsigned int new_var;
  s32 temp_a1;
  new_var = 0xFFFF;
  temp_a1 = (arg1 & new_var) * 0x10;
  *((s16 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 8)) = (s16) ((arg2 & new_var) << 6);
  *((s16 *) (((char *) (temp_a1 + (*((s32 *) (((char *) arg0) + 0x70))))) + 0xA)) = (s16) ((arg3 & new_var) << 6);
}
