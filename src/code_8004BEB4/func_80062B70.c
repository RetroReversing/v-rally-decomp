#include "common.h"

void *func_800592AC();
s32 func_800592F4();
extern s32 D_800C3558;
extern void *D_800C35A0;

void func_80062B70(void)
{
  s32 var_a0;
  u8 var_a1;
  void *var_v1;
  void *temp_a2;

  if (D_800C3558 == 2)
  {
    var_v1 = *((void **) (((char *) func_800592AC(3)) + 0x28));
    var_a0 = 0;
    do
    {
      var_a0 += 1;
      *((u16 *) (((char *) var_v1) + 6)) += 0x10;
      var_v1 = *((void **) var_v1);
    } while ((u8) var_a0 < 3);
  }
  func_800592F4(2, ((u8 *) D_800C35A0)[0x30]);
  temp_a2 = D_800C35A0;
  if (*((u16 *) (((char *) temp_a2) + 0xE)) == 1)
  {
    if (*((s32 *) (((char *) temp_a2) + 0x18)) == 0x10001)
    {
      func_800592F4(3, 1);
    }
    else
    {
      *((u16 *) (((char *) temp_a2) + 0x18)) = 0;
      *((u16 *) (((char *) temp_a2) + 0x1A)) = 1;
      func_800592F4(3, 0);
    }
  }
  else
  {
    if (*((u16 *) (((char *) temp_a2) + 0x18)) != 0)
    {
      func_800592F4(3, 1);
    }
    else
    {
      func_800592F4(3, (*((u16 *) (((char *) temp_a2) + 0x1A)) == 0) * 2);
    }
  }
}
