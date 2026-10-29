#include "snapshot29_0433f7af8f6d.h"

typedef struct 
{
  s32 w[5];
} IOArgs;
extern s32 func_80081040(s32, u8 *, s32, s32, IOArgs);
extern s32 func_80081E0C(u8 *);
extern u8 D_800AE850[];
extern u8 D_800C02AE[];
s32 func_80082094(void)
{
  u8 *new_var;
  s32 new_var2;
  s32 temp_v0;
  u8 *temp_v1;
  if ((*((s32 *) (D_800AE850 + 0x8ACC))) <= 0)
  {
    --(*((s32 *) (D_800AE850 + 0x8ACC)));
    *((s32 *) (D_800C02AE + 0x3092)) = 0;
    return -1;
  }
  temp_v0 = *((s32 *) (D_800C02AE + 0x3092));
  if (temp_v0 <= 0)
  {
    new_var2 = *((s32 *) (D_800AE850 + 0x2358));
    func_80081040(((*((s32 *) (D_800AE850 + 0x8AB0))) + (*((s32 *) (D_800C02AE + 0x30A6)))) + 0x2000, *((u8 **) (D_800C02AE + 0x308A)), 0x2000, new_var2, *((IOArgs *) (D_800AE850 + 0x235C)));
    *((s32 *) (D_800C02AE + 0x3092)) = 0x2000;
    *((s32 *) (D_800C02AE + 0x30A6)) += 0x2000;
    *((u8 **) (D_800C02AE + 0x308E)) = *((u8 **) (D_800C02AE + 0x308A));
    new_var = D_800C02AE;
    func_80081E0C(*((u8 **) (new_var + 0x308A)));
    ;
  }
  temp_v1 = *((u8 **) (D_800C02AE + 0x308E));
  *((s32 *) (D_800C02AE + 0x3092)) = (*((s32 *) (D_800C02AE + 0x3092))) - 1;
  *((u8 **) (D_800C02AE + 0x308E)) = temp_v1 + 1;
  return *temp_v1;
}
