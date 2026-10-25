#include "common.h"

s8 func_800857C0();
extern char D_800AE850[];

void func_8002FB64(void)
{
  u8 i;
  u32 n;

  n = 0;
  for (i = 0; i < 4; n = ++i) {
    *((s32 *) (D_800AE850 + 0x2394 + (i << 4))) = 0;
    *((s8 *) (D_800AE850 + 0x239C + (i << 4))) = func_800857C0(i, 2);
    *((s8 *) (D_800AE850 + 0x239D + (i << 4))) = 0;
  }
}
