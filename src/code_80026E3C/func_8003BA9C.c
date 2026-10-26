#include "common.h"

extern void *D_800C35A0;
void func_8003BA9C(void *arg0)
{
  s32 temp_a1;
  u16 *new_var;
  void *temp_v0;
  temp_v0 = *((void **) (((s8 *) (*((void **) (((s8 *) arg0) + 0xA8)))) + 0x24));
  if (temp_v0 != NULL)
  {
    new_var = (u16 *) (((s8 *) D_800C35A0) + 0xE);
    temp_a1 = *((s32 *) (((s8 *) (*((void **) (((s8 *) temp_v0) + 0x5C)))) + 0x60));
    *((s16 *) (((s8 *) arg0) + 0x7A)) = (s16) temp_a1;
    if ((*new_var) == 2)
    {
      *((s16 *) (((s8 *) arg0) + 0x7A)) = (s16) (temp_a1 + 4);
    }
  }
}
