#include "common.h"

extern char D_800C02AE[];
void func_8003BA9C(void *arg0)
{
  s32 temp_a1;
  u16 *new_var;
  void *temp_v0;
  temp_v0 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
  if (temp_v0 != NULL)
  {
    new_var = (u16 *) (((char *) (*((void **) (D_800C02AE + 0x32F2)))) + 0xE);
    temp_a1 = *((s32 *) (((char *) (*((void **) (((char *) temp_v0) + 0x5C)))) + 0x60));
    *((s16 *) (((char *) arg0) + 0x7A)) = (s16) temp_a1;
    if ((*new_var) == 2)
    {
      *((s16 *) (((char *) arg0) + 0x7A)) = (s16) (temp_a1 + 4);
    }
  }
}
