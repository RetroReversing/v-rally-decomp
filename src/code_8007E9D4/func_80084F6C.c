#include "common.h"

extern u8 *D_800A1B70;
void func_80084F6C(u8 arg0)
{
  int new_var;
  u8 i;
  u8 *base;
  u32 *p;
  base = D_800A1B70;
  p = (u32 *) (base + (arg0 * 0x38));
  ;
  i = 0;
  do
  {
    new_var = 0xAC;
    ((u32 *) (((u8 *) ((u32 *) (base + (14 * (4 * arg0))))) + new_var))[i] = 0;
    i++;
  }
  while (i < 0xE);
}
