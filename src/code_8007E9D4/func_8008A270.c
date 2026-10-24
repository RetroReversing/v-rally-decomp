#include "common.h"

void func_8008A270(char *arg0, int arg1, int arg2)
{
  char *new_var;
  int i = (arg1 & 0xFFFF) * 5;
  new_var = (*((char **) (arg0 + 0x10))) + ((i * 2) * 2);
  *((int *) (new_var + 0x10)) = arg2;
}
