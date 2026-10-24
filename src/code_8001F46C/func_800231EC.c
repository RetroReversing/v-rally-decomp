#include "common.h"

void *func_800231EC(int *arg0, unsigned char arg1)
{
  char *p;
  int new_var;
  new_var = !arg0;
  if (new_var)
  {
 do { return 0; } while (0);
  }
  for (p = *((char **) arg0); p; p = *((char **) (p + 4)))
  {
    if (((*((unsigned int *) (p + 0x14))) & arg1) == arg1)
    {
      return p;
    }
  }

  return 0;
}
