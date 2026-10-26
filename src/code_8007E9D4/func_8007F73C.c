#include "common.h"

s32 osRecvMesg();
extern char D_800AE850[];
s32 func_8007F73C(s32 arg0, s32 arg1)
{
  int new_var;
  s32 *sp10;
  int new_var2;
  new_var2 = 0;
  osRecvMesg(((arg0 + arg1) * 0x5C) + (D_800AE850 + 0x5924), &sp10, 1);
  if (sp10 == NULL)
  {
    if (arg0)
    {
      return new_var2;
    }
    else
    {
      return new_var2;
    }
  }
  new_var = *sp10;
  return new_var;
}
