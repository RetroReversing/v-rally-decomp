#include "common.h"

void func_800561FC(void *arg0, u32 *arg1)
{
  s32 i;
  s32 j;
  s32 n;
  u16 *p;
  u16 *q;
  u16 *base;
  u16 v;
  char pad[16];
  switch (*((u16 *) (((u8 *) arg0) + 6)))
  {
    case 26:
      n = *((u16 *) (((u8 *) arg0) + 4));
      base = *((u16 **) arg0);
      i = 0;
      if (n > 0)
    {
      do
      {
        j = 0;
        p = base;
        do
        {
          v = base[j];
          if ((*arg1) < v)
          {
            *arg1 = v;
          }
          j++;
        }
        while (j < 3);
        i++;
        base += 7;
      }
      while (i < (*((u16 *) (((u8 *) arg0) + 4))));
    }
      break;

    case 30:
      n = *((u16 *) (((u8 *) arg0) + 4));
      base = *((u16 **) arg0);
      i = 0;
      if (n > 0)
    {
      do
      {
        j = 0;
        p = base;
        do
        {
          v = *p;
          if ((*arg1) < v)
          {
            *arg1 = v;
          }
          j++;
          p++;
        }
        while (j < 4);
        i++;
        base += 9;
      }
      while (i < *((u16 *) (((u8 *) arg0) + 4)));
    }

  }

}
