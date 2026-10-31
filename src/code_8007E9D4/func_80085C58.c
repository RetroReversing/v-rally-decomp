#include "decompdecomp_sync_0433f7af8f6d1c74c1d3.h"
#line 1 "func.c"
extern s32 func_800863B0(s32, s32);
extern s32 osMotorInit(void *, void *, s32);
extern void *D_800A1B70;
extern u8 D_800AE850;
void func_80085C58(void)
{
  unsigned char var_s0;
  s32 var_s2;
  void *temp_a0;
  void *temp_a2;
  void *temp_v1;
  unsigned char new_var;
  void *temp_v1_2;
  void *temp_v1_3;
  temp_a2 = D_800A1B70;
  var_s2 = 0;
  if ((*((s32 *) (((u8 *) temp_a2) + 4))) > 0)
  {
    do
    {
      var_s0 = var_s2 & 0xFF;
      temp_v1 = ((u8 *) temp_a2) + (var_s0 * 4);
      if (((*((u16 *) (((u8 *) temp_v1) + 0xC))) & 4) && ((*((u8 *) (((u8 *) temp_v1) + 0xE))) & 1))
      {
        if ((osMotorInit((&D_800AE850) + 0x5A38, ((u8 *) temp_a2) + ((var_s0 * 0x68) + 0x18C), var_s0) & 0xFF) == 0)
        {
          func_800863B0(var_s0, 0);
          temp_v1_2 = ((u8 *) D_800A1B70) + (var_s0 * 0x18);
          *((s32 *) (((u8 *) temp_v1_2) + 0x330)) = 1;
          *((volatile s32 *) (((u8 *) temp_v1_2) + 0x334)) = 0;
        }
        else
        {
          temp_v1_3 = ((u8 *) D_800A1B70) + (var_s0 * 0x18);
          *((s32 *) (((u8 *) temp_v1_3) + 0x330)) = 0;
          var_s0 = var_s2 & 0xFF;
          *((volatile s32 *) (((u8 *) temp_v1_3) + 0x334)) = 0;
        }
      }
      else
      {
        temp_a0 = (char *) ((u8 *) D_800A1B70);
        temp_a0 += (s32) ((var_s2 & 0xFF) * 0x18);
        *((s32 *) (((u8 *) temp_a0) + 0x330)) = 0;
        *((s32 *) (((u8 *) temp_a0) + 0x334)) = 0;
      }
      temp_a2 = D_800A1B70;
      var_s2 += 1;
      var_s0 = (new_var = var_s2 & 0xFF);
    }
    while ((var_s2 & 0xFF) < (*((s32 *) (((u8 *) D_800A1B70) + 4))));
  }
}


