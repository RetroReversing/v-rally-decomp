#include "common.h"

extern char *D_800A1B70;
int func_800857C0(int arg0)
{
  char *new_var;
  char *p = D_800A1B70;
  unsigned char i = arg0;
  new_var = p + (i * 0x18);
  return (*((int *) (new_var + 0x330))) == 1;
}
