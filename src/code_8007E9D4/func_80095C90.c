#include "common.h"

s32 func_8008B4D4();
s32 func_8008BD90();
s32 func_8008BDB0();
extern char D_800A2518[];
extern void *D_800A2520;
static inline char *inline_fn()
{
  return ((char *) D_800A2520) + 0x10;
}

void func_80095C90(void)
{
  int new_var;
  s32 temp_s0;
  temp_s0 = func_8008BD90();
  new_var = 2;
  *((s16 *) inline_fn()) = new_var;
  func_8008B4D4(&D_800A2518, 2);
  func_8008BDB0(temp_s0);
}
