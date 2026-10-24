#include "common.h"

extern s32 D_8009D4E8;
extern s32 D_8009D4EC;
static inline char *inline_fn(void *arg0)
{
  return ((char *) arg0) + 0x14;
}

void func_800192D0(void *arg0)
{
  char *new_var;
  int new_var2;
  *((s32 *) (((char *) arg0) + (new_var2 = 0x18))) += D_8009D4EC;
  new_var = ((char *) arg0) + 0x10;
  if (1)
  {
    *((s32 *) new_var) += D_8009D4E8;
    *((s32 *) inline_fn(arg0)) += D_8009D4EC;
    if (0)
    {
    }
    *((s32 *) (((char *) arg0) + 0x20)) += D_8009D4EC;
  }
}
