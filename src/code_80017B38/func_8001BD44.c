#include "common.h"

extern void (*D_800B55EC)(void);
extern s32 D_800B7038;
void func_8001BD44(void)
{
  s32 *temp_a0;
  s32 new_var3;
  s32 temp_v0;
  s32 temp_v1;
  s32 *new_var;
  unsigned long new_var2;
  D_800B55EC();
  temp_a0 = &D_800B7038;
  if (1)
  {
    temp_v1 = *temp_a0;
  }
  new_var2 = temp_v1;
  *temp_a0 = 1 - new_var2;
  new_var = temp_a0;
  temp_v0 = D_800B7038 * 4;
  temp_v1 = *((s32 *) ((((char *) new_var) - (-temp_v0)) - 0x10));
  temp_a0 = (s32 *) (((char *) temp_a0) - 8);
  new_var3 = temp_v1;
  *((s32 *) (((char *) temp_a0) + temp_v0)) = new_var3;
}
