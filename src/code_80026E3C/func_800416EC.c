#include "common.h"

extern u8 D_800C02AE[];
extern u8 *D_800D0634[];
extern s32 D_8009FFE4;
extern u8 D_800A17F0;
extern unsigned char D_800A4CB4[];
extern u8 D_800A4CBC[];
extern u8 D_800A4CC4[];
extern u8 D_800A4CCC[];
extern u8 D_800A4CD4[];
extern u8 D_800A4CDC[];
extern u8 D_800A4CE4[];
extern u8 D_800A4CEC[];
extern u8 D_800A4CF4[];
extern u8 D_800A4CFC[];
extern u8 D_800A4D04[];
void func_800416EC(void)
{
  u8 *obj;
  u8 *a1;
  u8 s3;
  s32 mode;
  u16 s0;
  u16 s1;
  u16 s2;
  s3 = 0;
  ;
  switch (*(u16*)(*(u8**)(D_800C02AE+0x32F2)+0x1E)) {
  case 7: s3=1; break;
  case 8: if (D_800A17F0==0) func_80077280(); break;
  }
  if ((!((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x2C))) & 0x10)) && ((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x1E))) == 7))
  {
    mode = D_8009FFE4;
    *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x1E)) = 0;
    switch (mode)
    {
      case 0:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 5;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 4;
        break;

      case 1:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 7;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 4;
        break;

      case 2:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 3;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 1;
        break;

      case 3:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 2;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 5;
        break;

      case 4:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 1;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 3;
        break;

      case 5:
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x20)) = 6;
        *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x22)) = 2;
        break;

    }

    D_8009FFE4++;
    if (D_8009FFE4 >= 6)
    {
      D_8009FFE4 = 0;
    }
  }
  obj = *((u8 **) (D_800C02AE + 0x32F2));
  s1 = *((u16 *) (obj + 0x1E));
  s2 = *((u16 *) (obj + 0x20));
  s0 = *((u16 *) (obj + 0x22));
  func_8002B618(D_800D0634[s1] + (708 * s2), D_800A4CB4);
  if (s0 < 9)
  {
    switch (s0)
    {
      case 0:
        a1 = D_800A4CBC;
        break;

      case 1:
        a1 = D_800A4CC4;
        break;

      case 2:
        a1 = D_800A4CCC;
        break;

      case 3:
        a1 = D_800A4CD4;
        break;

      case 4:
        a1 = D_800A4CDC;
        break;

      case 5:
        a1 = D_800A4CE4;
        break;

      case 6:
        a1 = D_800A4CEC;
        break;

      case 7:
        a1 = D_800A4CF4;
        break;

      case 8:
        a1 = D_800A4CFC;
        break;

    }

    func_8002B618(D_800D0634[s1] + (708 * s2), a1);
  }
  if (s3 != 0)
  {
    ;
    *((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0x1E)) = 7;
  }
  func_8002B618(D_800D0634[s1] + (708 * s2), D_800A4D04);
}
