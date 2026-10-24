#include "common.h"

extern s32 D_800C35A0;
static inline u8 inline_fn(void *arg0)
{
  return *((u8 *) (((s8 *) arg0) + 8));
}

static inline int inline_fn2(s32 arg0, int arg1)
{
  return arg0 + (arg1 * 0x28);
}

s32 func_8006F820(void *arg0, s32 arg1)
{
  void *temp_a0;
  s8 *new_var;
  if ((*((u8 *) (((s8 *) arg0) + 0xC))) != 0)
  {
    ;
    new_var = (s8 *) arg0;
    if ((((*((u8 *) (((s8 *) arg0) + 6))) == (*((u8 *) (((s8 *) inline_fn2(D_800C35A0, arg1 & 0xFF)) + 0x44)))) && ((*((u8 *) (new_var + 7))) == (*((u8 *) (((s8 *) inline_fn2(D_800C35A0, arg1 & 0xFF)) + 0x45))))) && (inline_fn(arg0) == (*((u8 *) (((s8 *) inline_fn2(D_800C35A0, arg1 & 0xFF)) + 0x46)))))
    {
      *((u8 *) (((s8 *) arg0) + 0xC)) = 0U;
      return 1;
    }
    return 0;
  }
  return 0;
}
