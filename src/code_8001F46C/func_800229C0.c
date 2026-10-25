#include "common.h"

typedef struct Stage
{
  s32 count;
  s32 pad[3];
  void (*fn)(void *, void *, s32, void *);
  s32 pad2[2];
} Stage;
static inline void *inline_fn(s32 *arg0)
{
  return (void *) arg0;
}

void func_800229C0(s32 arg0, u8 *arg1, s32 unused, void *arg3)
{
  int new_var;
  s32 buf[2];
  u32 i = 0;
  void *var_a3 = arg3;
  new_var = ((*((Stage **) (arg1 + 0xD0))) + arg0)->count != 0;
  if (new_var)
  {
    var_a3 = inline_fn(((s32 *) arg1) + arg0);
    do
    {
      ((s32 *) (*((s32 **) (((u8 *) var_a3) + 0x48))))[i] = ((s32 *) (*((s32 **) (((u8 *) var_a3) + 0x1C))))[i];
      i++;
    }
    while (i < ((u32) ((*((Stage **) (arg1 + 0xD0))) + arg0)->count));
  }
  ((*((Stage **) (arg1 + 0xD0))) + arg0)->fn(arg1, arg1, i, var_a3);
}
