#include "common.h"

extern u8 D_800C8324;
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
void func_80072C94(void *, s32);
void func_800234E0(void);
void func_8007301C(void)
{
  s32 *p = *((s32 **) (D_800AE850 + 0x73F0));
  s32 state = D_800C8324;
  s32 one = 1;
  void *node = (void *) (*p);
  switch (state)
  {
    case 0:
      return;

    case 1:
      func_80072C94(node, 0);
      break;

    case 3:
      if ((*((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0xE))) == one)
    {
      func_80072C94(node, 0);
      break;
    }
      func_80072C94(node, 0);

    case 2:
      node = *((void **) (node + 4));
      if (((*((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0x1E))) == 0) && ((*((u16 *) ((*((void **) (D_800C02AE + 0x32F2))) + 0x1A))) == one))
    {
      node = *((void **) (node - -4));
    }
      func_80072C94(node, 1);
      break;

  }

  D_800C8324 = 0;
  func_800234E0();
}
