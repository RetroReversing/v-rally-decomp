#include "common.h"

s32 func_80080F08(u8 *arg0)
{
  u8 *base;
  s32 total;

  base = arg0;
  arg0 = arg0 - 0x14;
  if (base[-9] != 0) {
    arg0 = arg0 + 0x14;
    total = 0;
    if (arg0 != NULL) {
      do {
        if (arg0[0xA] == 0) {
          total += *(s32 *)arg0 - (0x14 + (s32)arg0);
        }
        arg0 = *(u8 **)arg0;
      } while (arg0 != NULL);
    }
  } else {
    total = (*(s32 *)(base - 0x14) - (s32)arg0) - 0x34;
  }
  return total;
}
