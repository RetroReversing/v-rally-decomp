#include "snapshot31_verified.h"

void *func_800592AC();
s32 func_800592F4();
void *func_8005A744();
s32 func_8008A0D8();
extern void *D_800A1468;
extern u8 D_800A154C[];
extern s32 D_800A18D0;
extern char D_800C02AE[];
extern void *D_800C3508;
extern void *D_800C35A0;
void func_8005FAD0(void)
{
  s32 temp_a0;
  s32 temp_s0;
  u8 var_a1;
  s32 var_s1;
  s32 var_v0;
  long new_var;
  u16 temp_v1;
  s32 temp_v1_2;
  func_8008A0D8(D_800C3508, 0x20U, 0);
  func_8008A0D8(D_800C3508, 0x21U, 0);
  var_s1 = 0;
  do
  {
    new_var = var_s1 & 0xFF;
    temp_s0 = new_var;
    func_8008A0D8(D_800C3508, *(D_800A154C + temp_s0), 0);
    var_s1 += 1;
    *((s8 *) (((char *) func_8005A744((*(D_800A154C + new_var)) - 0x17, *((s32 *) (((char *) D_800A1468) + 0xC)))) + 0x41)) = 0;
  }
  while (((u32) (var_s1 & 0xFF)) < 3U);
  func_8008A0D8(D_800C3508, 0x17U, 0);
  *((s8 *) (((char *) func_800592AC(0)) + 0x41)) = 0;
  func_8008A0D8(D_800C3508, 0x18U, 0);
  *((s8 *) (((char *) func_800592AC(1)) + 0x41)) = 0;
  temp_v1 = *((u16 *) (((char *) D_800C35A0) + 0x2A));
  temp_a0 = 0;
  if (temp_v1 & 0x1000)
  {
    temp_a0 = 1;
  }
  var_a1 = temp_a0;
  if (temp_v1 & 0x2000)
  {
    var_a1 = temp_a0 + 1;
  }
  if (temp_v1 & 0x4000)
  {
    var_a1 += 1;
  }
  func_800592F4(0x1B, var_a1 & 0xFF);
  func_800592F4(0x1D, (*((u16 *) (((char *) D_800C35A0) + 0x38))) != 0);
  func_800592F4(0x1A, (((u16) (*((u16 *) (((char *) D_800C35A0) + 0x2C)))) >> 8) & 1);
  if (!(D_800A18D0 & 0x10))
  {
    {
      u16 *flags = (u16 *) (((u8 *) D_800C35A0) + 0x2C);
      do
      {
        void *menu = D_800C3508;
        *flags |= 0x100;
        func_8008A0D8(menu, 0x1A, 0);
      }
      while (0);
    }
    *((s8 *) (((char *) func_800592AC(3)) + 0x41)) = 0;
  }
  func_800592F4(0x1E, (((u16) (*((u16 *) (((char *) D_800C35A0) + 0x2C)))) >> 0xE) & 1);
  if (!(D_800A18D0 & 0x10))
  {
    func_8008A0D8(D_800C3508, 0x1EU, 0);
    *((s8 *) (((char *) func_800592AC(7)) + 0x41)) = 0;
  }
  func_800592F4(0x17, (((u16) (*((u16 *) (((char *) D_800C35A0) + 0x2C)))) >> 9) & 1);
  if (!(D_800A18D0 & 0x10))
  {
    func_8008A0D8(D_800C3508, 0x17U, 0);
    *((s8 *) (((char *) func_800592AC(0)) + 0x41)) = 0;
  }
  func_800592F4(0x22, (((u16) (*((u16 *) (((char *) D_800C35A0) + 0x2C)))) >> 0xC) & 1);
  temp_v1_2 = *((u8 *) (((char *) D_800C35A0) + 0x2F));
  for (var_s1 = 0; ((u32) (var_s1 & 255)) < 6; var_s1++)
  {
    if (!((temp_v1_2 >> var_s1) & 1))
    {
      break;
    }
  }

  func_800592F4(0x1C, var_s1 & 0xFF);
  *((s8 *) (((char *) (((*((s16 *) (((char *) D_800C3508) + 2))) * 0x14) + (*((s32 *) (((char *) D_800C3508) + 0x10))))) + 0xE)) = 0x19;
}
