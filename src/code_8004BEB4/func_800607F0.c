#include "common.h"

extern char D_800AE850[];
int func_800607F0(unsigned char *arg0, unsigned char *arg1)
{
  char *new_var2;
  char *new_var;
  int pad;
  int new_var3;
  new_var = D_800AE850 + 0x18B8;
  new_var3 = 4;
  new_var2 = new_var + ((*arg0) * 4);
  return (*((unsigned int *) (new_var + ((*arg1) * new_var3)))) < (pad = *((unsigned int *) new_var2));
}
