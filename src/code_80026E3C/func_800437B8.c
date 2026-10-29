#include "snapshot29_0433f7af8f6d.h"

s32 func_8001FEE8(void *);
s32 func_80022374(void *, s32 *, s32);
s32 func_800347A4(void *, void *);
s32 func_80042F40(void);
s32 func_80085778(s32, s32);
extern s32 D_800A4DFC;
extern s32 D_800AE44C;
extern s32 D_800A73E0;
extern s32 D_800AE850;
extern s32 D_800C02AE;
void func_800437B8(void *arg0, void *arg1)
{
  s32 temp_a0;
  s32 temp_a1;
  s32 temp_v0_2;
  s32 temp_v0_3;
  s32 var_s3;
  s32 var_v0 = 0;
  u16 temp_v0;
  s32 var_s1;
  void *temp_v1;
  void *var_a0;
  void *var_a0_2;
  void *var_s0;
  if (!((*((s32 *) (((char *) arg0) + 0x14))) & 0x80))
  {
    if ((*(*((s32 **) (((char *) arg0) + 0x48)))) < 4)
    {
      var_a0 = *(*((void ***) (((char *) (&D_800AE850)) + 0x72FC)));
      if (var_a0 != NULL)
      {
        loop_3:
        if ((*((s32 *) (((char *) var_a0) + 0x24))) != arg0)
        {
          var_a0 = *((void **) (((char *) var_a0) + 4));
          if (var_a0 != NULL)
          {
            goto loop_3;
          }
        }

      }
      func_80022374(var_a0 + 0x28, &D_800A4DFC, 2);
      *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x50)))) + 4)) = 1;
      temp_v1 = *((void **) (((char *) arg0) + 0x50));
      if ((*((s32 *) (((char *) temp_v1) + 0))) < 2)
      {
        *((s32 *) (((char *) temp_v1) + 0)) = 2;
      }
    }
  }
  func_800347A4(arg0, arg1);
  if (((u8) (*((u8 *) (((char *) arg1) + 4)))) >= 0x81U)
  {
    *((u8 *) (((char *) arg1) + 4)) = 0x80U;
  }
  *((s32 *) (((char *) arg0) + 0x14)) = (s32) ((*((s32 *) (((char *) arg0) + 0x14))) | 0x80);
  if ((*(*((s32 **) (((char *) arg0) + 0x48)))) < 4)
  {
    var_a0_2 = *((void **) (((char *) (&D_800C02AE)) + 0x32F2));
    temp_v0 = *((u16 *) (((char *) var_a0_2) + 0x1E));
    if (((temp_v0 == 0) | (temp_v0 == 5)) != 0)
    {
      var_s0 = *(*((void ***) (((char *) (&D_800AE850)) + 0x73F0)));
      var_s1 = 1;
      if (var_s0 != NULL)
      {
        do
        {
          if ((*(*((s32 **) (((char *) var_s0) + 0x48)))) < 4)
          {
            var_s1 &= -(((*((s32 *) (((char *) var_s0) + 0x14))) & 0x80) != 0);
          }
          var_s0 = *((void **) (((char *) var_s0) + 4));
        }
        while (var_s0 != NULL);
      }
      if (var_s1 != 0)
      {
        goto block_34;
      }
    }
    else
    {
      var_s0 = *(*((void ***) (((char *) (&D_800AE850)) + 0x73F0)));
      var_s1 = *((u16 *) (((char *) var_a0_2) + 0xE));
      var_s3 = 0;
      if (var_s0 != NULL)
      {
        do
        {
          if ((*(*((s32 **) (((char *) var_s0) + 0x48)))) < 4)
          {
            temp_v0_2 = func_8001FEE8(var_s0);
            temp_a1 = *((s32 *) (((char *) var_s0) + 0x14));
            temp_a0 = temp_a1 & 0x100;
            var_s1 -= temp_a0 != 0;
            if ((((temp_a0 == 0) && (((u32) (temp_v0_2 + 5)) < 0xBU)) && ((*((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x6C)))) + 0x10))) == 0)) && (temp_a1 & 0x200))
            {
              var_s3 += 1;
              var_s1 -= 1;
            }
          }
          var_s0 = *((void **) (((char *) var_s0) + 4));
        }
        while (var_s0 != NULL);
      }
      if (var_s1 == 0)
      {
        if ((*(*((s32 **) (((char *) arg0) + 0x48)))) < 4)
        {
          D_800AE44C = (void *) ((*((void **) (((char *) (&D_800A73E0)) + 0x706C))) + 1);
        }
        var_a0_2 = *((void **) (((char *) (&D_800A73E0)) + 0x706C));
        temp_v0_3 = (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE))) * 0x64;
        if ((var_a0_2 == temp_v0_3) || (var_a0_2 == (temp_v0_3 + 1)))
        {
          var_v0 = 1;
        }
        if (((var_v0 & 0xFF) != 0) && (var_s3 != (*((u16 *) (((char *) (*((void **) (((char *) (&D_800C02AE)) + 0x32F2)))) + 0xE)))))
        {
          block_34:
          *(s32 *)0x800B6880 = 0;
          func_80042F40();

          func_80085778(0, 0x1000);
          func_80085778(0, 0x8000);
        }
      }
    }
  }
}
