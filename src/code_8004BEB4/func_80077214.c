#include "common.h"

extern u16 D_800B0C64;
extern u16 D_800B0C66;
extern char D_800AE850[];
s32 func_80027CDC();
s32 func_80027CFC();
void func_80077214(s32 arg0, void *arg1)
{
  u16 idx;
  u32 lim;
  s32 *tbl;
  s32 *new_var;
  s32 val;
  idx = D_800B0C64;
  tbl = *((s32 **) (D_800AE850 + 0x240C));
  new_var = &tbl[idx];
  lim = D_800B0C66;
  val = *new_var;
  if (idx < lim)
  {
    D_800B0C64 = idx + 1;
  }
  func_80027CDC(val, arg1);
  func_80027CFC(arg1);
}
