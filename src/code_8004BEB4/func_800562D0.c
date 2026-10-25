#include "common.h"

s32 func_80055D18();
s32 func_80055EE8();
void func_800562D0(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4)
{
  u16 new_var;
  s32 i;
  u16 t;
  arg1 = arg1;
  if (arg4 != 0)
  {
    for (i = 0; i < arg4; i++)
    {
      new_var = *((u16 *) (((char *) arg1) + 6));
      t = new_var;
      switch (t)
      {
        case 0x1A:
          func_80055D18(arg0, arg1, arg2, arg3);
          break;

        case 0x1E:
          func_80055EE8(arg0, arg1, arg2, arg3);
          break;

      }

      arg1 = ((char *) arg1) + 8;
    }

  }
}
