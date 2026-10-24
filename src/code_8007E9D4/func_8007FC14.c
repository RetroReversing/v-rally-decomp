#include "common.h"

extern volatile int D_800A19B0;
void func_8007FC14(void)
{
  int new_var;
  s32 *new_var2;
  new_var2 = &D_800A19B0;
  if ((*new_var2) == 1)
  {
    ;
    do
    {
    }
    while (D_800A19B0 == 1);
  }
}
