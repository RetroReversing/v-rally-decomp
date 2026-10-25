#include "common.h"

u32 func_80080EA0(u8 *arg0)
{
  int new_var;
  u32 max;
  u32 temp;
  u8 *p;
  u8 *node;
  node = arg0;
  arg0 = arg0 - 0x14;
  if (node[-9] != 0)
  {
    p = arg0 + 0x14;
    max = 0;
    if (p != NULL)
    {
      do
      {
        if (p[0xA] == 0)
        {
          new_var = (*((u32 *) p)) - 0x14;
          temp = new_var - ((u32) p);
          if (max < temp)
          {
            max = temp;
          }
        }
        p = *((u8 **) p);
      }
      while (p != NULL);
    }
  }
  else
  {
    max = ((*((u32 *) (node - 0x14))) - ((u32) arg0)) - 0x34;
  }
  return max;
}
