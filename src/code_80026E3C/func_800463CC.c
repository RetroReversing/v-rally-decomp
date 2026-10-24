#include "common.h"

extern signed char D_800C34D0;
extern char D_800C02AE[];
void func_800463CC(void *arg0, s32 arg1, void *arg2)
{
  u16 temp_a1;
  void *temp_v1;
  unsigned int new_var;
  temp_v1 = *((void **) (((char *) arg2) + 0x70));
  temp_a1 = *((u16 *) (((char *) arg0) + 0));
  if ((*((s32 *) (((char *) temp_v1) + 0xC))) != (new_var = temp_a1))
  {
    *((s32 *) (((char *) temp_v1) + 0xC)) = (s32) new_var;
    if (((*(*((s32 **) (((char *) arg2) + 0x48)))) < 4) && ((*((s32 *) (((char *) arg0) + 4))) == 1))
    {
      D_800C34D0 = (s8) new_var;
    }
  }
}
