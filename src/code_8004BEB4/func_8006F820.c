#include "common.h"

extern int D_800C35A0;
extern char D_800C02AE[];
static inline u8 inline_fn(void *arg0)
{
  return *((u8 *) (((char *) arg0) + 8));
}

static inline int inline_fn2(int arg0, s32 arg1)
{
  return arg0 + ((arg1 & 0xFF) * 0x28);
}

s32 func_8006F820(void *arg0, s32 arg1)
{
  void *temp_a0;
  u8 new_var;
  if ((*((u8 *) (((char *) arg0) + 0xC))) != 0)
  {
    ;
    new_var = *((u8 *) (((char *) inline_fn2(D_800C35A0, arg1)) + 0x44));
    if ((((*((u8 *) (((char *) arg0) + 6))) == new_var) && ((*((u8 *) (((char *) arg0) + 7))) == (*((u8 *) (((char *) (D_800C35A0 + ((arg1 & 0xFF) * 0x28))) + 0x45))))) && (inline_fn(arg0) == (*((u8 *) (((char *) (D_800C35A0 + ((arg1 & 0xFF) * 0x28))) + 0x46)))))
    {
      *((u8 *) (((char *) arg0) + 0xC)) = 0U;
      return 1;
    }
    return 0;
  }
  return 0;
}
