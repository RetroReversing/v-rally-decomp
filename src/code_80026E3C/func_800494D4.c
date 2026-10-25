#include "common.h"

extern s32 D_8009D538;
extern char D_800AE850[];
extern char D_800C02AE[];

void func_800494D4(s32 arg0)
{
  s32 temp_v1;

  if (!(D_8009D538 & 0x4000))
  {
    D_8009D538 |= 0x4000;
  }
  if (((u16 *) (*((void **) (D_800C02AE + 0x32F2))))[0xF] == 0)
  {
    temp_v1 = (arg0 & 0xFF) * 0x44;
    *((u16 *) (D_800AE850 + 0x2410 + temp_v1)) |= 2;
  }
}
