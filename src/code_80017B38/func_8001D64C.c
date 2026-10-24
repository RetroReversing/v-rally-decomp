#include "common.h"

extern char D_800AE850[];
static inline void *inline_fn(void **arg0)
{
  return *arg0;
}

void func_8001D64C(void *arg0)
{
  s32 *new_var;
  char *new_var2;
  if (inline_fn((void **) (D_800AE850 + 0x8A28)) != NULL)
  {
    *((s8 *) (((char *) inline_fn((void **) (D_800AE850 + 0x8A28))) + 0x90)) = (s8) (*((s32 *) (((char *) arg0) + 0x90)));
    new_var2 = ((char *) arg0) + 0xDC;
    new_var = (s32 *) new_var2;
    *((s8 *) (((char *) inline_fn((void **) (D_800AE850 + 0x8A28))) + 0x91)) = (s8) (*new_var);
    *((s8 *) (((char *) inline_fn((void **) (D_800AE850 + 0x8A28))) + 0x92)) = (s8) (*((s32 *) (((char *) arg0) + 0x128)));
    *((s8 *) (((char *) inline_fn((void **) (D_800AE850 + 0x8A28))) + 0x93)) = (s8) (*((s32 *) (((char *) arg0) + 0x174)));
  }
}
