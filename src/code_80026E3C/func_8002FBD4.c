#include "common.h"

s32 func_800857C0();
s32 func_800857EC();
extern s32 D_8009D538;
extern void *D_800A0384;
extern u8 D_800AE850[];
extern char D_800C02AE[];
static inline int inline_fn(u8 **arg0)
{
  return (*((s32 *) (*arg0))) * 0x10;
}

void func_8002FBD4(u8 *arg0, s32 arg1, s32 arg2)
{
  s32 idx;
  s32 off;
  u8 s0;
  if ((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x1E))) == 7)
  {
    return;
  }
  if (D_8009D538 & 0x800)
  {
    return;
  }
  idx = *((s32 *) (*((u8 **) (arg0 + 0x48))));
  if (idx >= 4)
  {
    return;
  }
  if ((*((u8 *) (((u8 *) D_800A0384) + 0x384))) != 0)
  {
    return;
  }
  if ((*((s32 *) ((*((u8 **) (arg0 + 0x6C))) + 0x34))) != 0)
  {
    return;
  }
  off = idx << 4;
  if (D_800AE850[0x239D + off] != 0)
  {
    return;
  }
  if ((*((s32 *) (arg0 + 0x14))) & 0x100)
  {
    return;
  }
  s0 = D_800AE850[0x239C + off];
  if (s0 != func_800857C0(idx & 0xFF, 2))
  {
    *((u8 *) ((D_800AE850 + 0x239D) + inline_fn((u8 **) (arg0 + 0x48)))) = 1;
    *((s32 *) ((D_800AE850 + 0x2394) + inline_fn((u8 **) (arg0 + 0x48)))) = 0;
  }
  off = (*((s32 *) (*((u8 **) (arg0 + 0x48))))) << 4;
  if (D_800AE850[0x239D + off] != 0)
  {
    return;
  }
  if ((*((s32 *) ((D_800AE850 + 0x2394) + off))) != 0)
  {
    return;
  }
  *((s32 *) ((D_800AE850 + 0x2394) + off)) = 1;
  *((u16 *) ((D_800AE850 + 0x2392) + inline_fn((u8 **) (arg0 + 0x48)))) = 0;
  *((u8 *) ((D_800AE850 + 0x2390) + inline_fn((u8 **) (arg0 + 0x48)))) = arg2;
  func_800857EC(*((u8 *) ((*((u8 **) (arg0 + 0x48))) + 3)), 2, arg1 & 0xFF);
}
