#include "common.h"

extern u8 D_800C02AE[];
extern u8 D_800AE850[];
extern u8 D_800A4B48[];
s32 func_80022318(void *, void *);
void *func_8004240C(s32);
void func_8003F11C(u8 *arg0)
{
  u8 *temp_a2;
  s32 temp_v1;
  s32 var_a1;
  u8 *var_a0;
  u8 *temp_v0;
  u8 *temp_a0;
  u8 *temp_v1_2;
  s16 temp_a0_2;
  s16 temp_a1;
  temp_a2 = *((u8 **) ((*((u8 **) (arg0 + 0xA8))) + 0x24));
  if (temp_a2 != NULL)
  {
    *((u32 *) (arg0 + 0x80)) |= 4;
    temp_v1 = *((s32 *) (temp_a2 + 0x14));
    if (temp_v1 & 0x80)
    {
      var_a1 = *((s32 *) ((*((u8 **) (temp_a2 + 0x6C))) + 8));
      if ((var_a1 == 1) && (temp_v1 & 0x100))
      {
        *((s16 *) (arg0 + 0x7A)) = 1;
        temp_a0 = *((u8 **) (D_800C02AE + 0x32F2));
        *((u32 *) (arg0 + 0x80)) &= ~4;
        if ((*((u16 *) (temp_a0 + 0xE))) == var_a1)
        {
          if ((*((s16 *) (arg0 + 0xE))) >= 0x47)
          {
            *((s16 *) (arg0 + 0xE)) = 0x3C;
          }
        }
      }
      else
        if (!(temp_v1 & 0x100))
      {
        var_a1 = 0;
        for (var_a0 = *((u8 **) (*((u8 **) (D_800AE850 + 0x73F0)))); var_a0 != NULL; var_a0 = *((u8 **) (var_a0 + 4)))
        {
          if (((*((s32 *) (*((u8 **) (var_a0 + 0x48))))) < 4) && (var_a0 != temp_a2))
          {
            if ((*((s32 *) (var_a0 + 0x14))) & 0x100)
            {
              var_a1 = 1;
            }
          }
        }

        if (var_a1 == 0)
        {
          temp_v0 = func_8004240C(((*((u16 *) ((*((u8 **) (D_800C02AE + 0x32F2))) + 0xE))) * 2) + 2);
          if (func_80022318(temp_v0 + 0x28, D_800A4B48) != 0)
          {
            *((u32 *) (arg0 + 0x80)) |= 4;
          }
          else
          {
            *((s16 *) (arg0 + 0x7A)) = 0;
            temp_v1_2 = *((u8 **) ((*((u8 **) (arg0 + 0xA8))) + 0x178));
            temp_a0_2 = *((s16 *) (temp_v1_2 + 0xE));
            temp_a1 = *((s16 *) (temp_v1_2 + 0xA));
            *((u32 *) (arg0 + 0x80)) &= ~4;
            *((s16 *) (arg0 + 0xE)) = temp_a1 + (temp_a0_2 / 2);
          }
        }
      }
      ;
      *((s16 *) (arg0 + 0x70)) = -((*((u16 *) ((*((u8 **) ((*((u8 **) ((*((u8 **) (arg0 + 0xA4))) + 4))) + ((*((s16 *) (arg0 + 0x7A))) * 4)))) + 6))) >> 1);
    }
  }
}
