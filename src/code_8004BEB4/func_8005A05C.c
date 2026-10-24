#include "common.h"

extern void *D_800C5D28;
void func_8005A05C(s32 arg0)
{
  int new_var2;
  s32 var_a1;
  void *new_var;
  void *var_v1;
  new_var = *(*((void ***) (((s8 *) D_800C5D28) + 0x10)));
  var_v1 = new_var;
  if (var_v1 || var_a1)
  {
    var_a1 = 0;
  }
  else
  {
    var_v1 = *(*((void ***) (((s8 *) D_800C5D28) + 0x10)));
    var_a1 = 0;
  }
  if (var_v1 != NULL)
  {
    new_var2 = arg0 & 0xFF;
    loop_2:
    if ((var_a1 & 0xFF) == new_var2)
    {
      if (D_800C5D28)
      {
        *((s32 *) (((s8 *) var_v1) + 0xC)) = (s32) ((*((s32 *) (((s8 *) var_v1) + 0xC))) | 2);
        return;
      }
      else
      {
        *((s32 *) (((s8 *) var_v1) + 0xC)) = (s32) ((*((s32 *) (((s8 *) var_v1) + 0xC))) | 2);
        return;
      }
    }

    var_v1 = *((void **) (((s8 *) var_v1) + 4));
    var_a1 += 1;
    if (var_v1 == NULL)
    {
    }
    else
    {
      goto loop_2;
    }
  }
}
