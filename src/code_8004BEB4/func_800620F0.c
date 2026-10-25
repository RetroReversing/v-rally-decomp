#include "common.h"

extern char D_800C02AE[];
extern void *D_800A1468;
void *func_8005A744();
void func_800620F0(s32 arg0)
{
  u8 *a1;
  u8 *a3;
  u32 a2;
  a3 = func_8005A744(*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)), *((s32 *) (((char *) D_800A1468) + 0xC)));
  a1 = *((u8 **) (a3 + 0x28));
  a2 = 0;
  if (a3[0x4C] != a2)
  {
    a2 = a2;
    do
    {
      if ((a2 & 0xFF) == (arg0 & 0xFF))
      {
        a1[0xB] = 0x32;
        a1[0xC] = 0x32;
        a1[0xD] = 0x32;
        a1[0xE] = 0x64;
        return;
      }
      a1 = *((u8 **) a1);
      a2++;
    }
    while ((a2 & 0xFF) < a3[0x4C]);
  }
}
