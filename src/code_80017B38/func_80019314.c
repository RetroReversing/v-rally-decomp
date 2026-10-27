#include "common.h"

void func_800561FC(void *list, s32 *n);
void func_80019314(u8 *obj, s32 *a1, s32 *a2, s32 *a3)
{
  struct { s32 n; s32 pad[2]; } local;
#define n local.n
  u8 *info;
  s32 count;
  s32 *list;
  u16 *cmd;
  s32 i;
  if ((*((s16 *) (obj + 0x8))) != (-1))
  {
    info = *((u8 **) (obj + 0x18));
    count = *((u16 *) (info + 0x10));
    n = 0;
    list = *((s32 **) (info + 0x14));
    i = 0;
    if (count != 0)
    {
      ;
      do
      {
        switch ((u32) (((u16 *) (((u8 *) list) + 4))[1] - 0x18))
        {
          case 0:
            *a2 += ((u16 *) (((u8 *) list) + 4))[0];
            break;

          case 1:
            *a1 += ((u16 *) (((u8 *) list) + 4))[0];
            break;

          case 2:
            break;

          case 3:
            break;

          case 4:
            break;

          case 5:
            break;

          case 6:
            break;

          case 7:
            break;

          case 8:
            break;

          case 9:
            break;

          case 10:
            break;

          case 11:
            break;

          default:
            while (1)
          {
          }


        }

        func_800561FC(list, &n);
        cmd += 4;
        list += 2;
      }
      while ((++i) < count);
    }
    { s32 total = n + 1; n = total;
      *((s16 *) (obj + 0xA)) = total;
      *a3 += total;
    }
  }
}
