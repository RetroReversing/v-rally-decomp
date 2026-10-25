#include "common.h"

extern u8 *D_800C35A0;
extern u8 D_800AE850[];
u8 func_80078338(u8 arg0)
{
  u8 i;
  u8 n;
  u32 *tbl;

  n = 4;
  tbl = (u32 *) (D_800AE850 + 0x7E08 + *(u16 *) (D_800C35A0 + 0x20) * 16);
  i = 0;
  do {
    if (tbl[arg0] < tbl[i]) {
      n--;
    }
    i++;
  } while (i < 4);
  return n - 1;
}
