#include "common.h"

extern u8 D_800C02AE[];
u8 func_800556C4(s32 arg0)
{
  u8 *p;
  u16 i;
  u8 found;

  found = 0;
  i = 0;
  do {
    p = *(u8 **) (D_800C02AE + 0x3902 + i * 4);
    if (p != NULL) {
      if (*(s32 *) (p + 4) == arg0) {
        found = 1;
      }
    }
    i++;
  } while (found == 0 && i < 0x800);
  if (found != 0) {
    p[2] += 1;
  }
  return *(vu8 *)(p + 2);
}
