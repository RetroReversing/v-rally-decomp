#include "common.h"

extern s32 D_800C35A0;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8003EF20(void *arg0)
{
  void *temp_a0;
  u32 temp_a2;
  char *new_var2;
  s32 var_a0;
  s32 temp_v1_2;
  s16 var_v0;
  void *var_v1;
  u8 *new_var;
  temp_a0 = *((void **) (((u8 *) arg0) + 0xA8));
  var_v1 = *((void **) (((u8 *) temp_a0) + 0x24));
  if (var_v1 != NULL)
  {
    temp_a2 = *((u32 *) (((u8 *) (*((void **) (((u8 *) (*((void **) (((u8 *) temp_a0) + 0x24)))) + 0x6C)))) + 8));
    if (temp_a2 >= 2)
    {
      var_a0 = -1;
      var_v0 = (*((u16 *) (((u8 *) (*((void **) (((u8 *) temp_a0) + 0x178)))) + 0xA))) + 6;
    }
    else
    {
      var_a0 = 1;
      var_v0 = (*((u16 *) (((u8 *) (*((void **) (((u8 *) temp_a0) + 0x178)))) + 0xA))) + 0x10;
    }
    new_var2 = D_800AE850 + 0x73F0;
    *((s16 *) (((u8 *) arg0) + 0xE)) = var_v0;
    for (var_v1 = *(*((void ***) new_var2)); var_v1 != NULL; var_v1 = *((void **) (((u8 *) var_v1) + 4)))
    {
      if ((*((s32 *) (((u8 *) (*((void **) (((u8 *) var_v1) + 0x6C)))) + 8))) == (temp_a2 + var_a0))
      {
        break;
      }
    }

    if (var_v1 != NULL)
    {
      new_var = ((u8 *) ((D_800C35A0 + ((*((u8 *) ((D_800C35A0 + (*((s32 *) (((u8 *) (*((void **) (((u8 *) var_v1) + 0x48)))) + 0x2C)))) + 0x32))) * 0x28)) + (*((u16 *) (((u8 *) arg0) + 0x78))))) + 0x44;
      temp_v1_2 = *new_var;
      if (temp_v1_2 < 0x41)
      {
        *((s16 *) (((u8 *) arg0) + 0x7A)) = temp_v1_2 - 0x16;
      }
      else
        if (1)
      {
        *((s16 *) (((u8 *) arg0) + 0x7A)) = temp_v1_2 - 0x41;
      }
    }
  }
}
