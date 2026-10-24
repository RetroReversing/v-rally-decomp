#include "common.h"

s32 func_8008D090();
static inline char *inline_fn(void *arg0)
{
  return ((char *) arg0) + 0xE;
}

s32 func_8007F6E0(void *arg0)
{
  int new_var2;
  s32 *new_var3;
  void *new_var;
  s32 *sp10;
  *((u16 *) inline_fn(arg0)) |= 1;
  new_var2 = 0x10;
  new_var = arg0;
  new_var = new_var + new_var2;
  func_8008D090(new_var, &sp10, 1);
  new_var3 = sp10;
  *((u16 *) inline_fn(arg0)) &= 0xFFFE;
  if (sp10 == NULL)
  {
    if (new_var)
    {
      return 0;
    }
    else
    {
      return 0;
    }
  }
  return *new_var3;
}
