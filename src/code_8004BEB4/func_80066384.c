#include "common.h"

void *func_800592AC();
s32 func_80059618();
s32 func_800596F4();
s32 func_8006090C();
s32 func_8006A438();
extern char D_800C02AE[];
static inline u16 *inline_fn(char *arg0)
{
  return (u16 *) (((char *) (*((void **) (arg0 + 0x32F2)))) + 0xE);
}

void func_80066384(void)
{
  s32 var_s1;
  void *var_s2;
  void *temp_s0;
  u8 var_a1;
  u8 var_a2;
  u8 var_a3;
  u8 var_v0;

  func_8006A438();
  func_8006090C();
  var_s2 = func_800592AC(1);
  var_s1 = 0;
  if (*inline_fn(D_800C02AE) == 0)
  {
    return;
  }
  do
  {
    temp_s0 = *((void **)((char *)var_s2 + 0x28));
    if (*((u8 *)var_s2 + 0x42) != 0)
    {
      var_a1 = 0xDC;
      var_a2 = 0xDC;
      var_a3 = 0xE;
      var_v0 = *((u8 *)temp_s0 + 0xE);
      func_80059618(temp_s0, var_a1, var_a2, var_a3, var_v0);
    }
    else
    {
      var_a1 = *((u8 *)temp_s0 + 0xB);
      var_a2 = *((u8 *)temp_s0 + 0xC);
      var_a3 = *((u8 *)temp_s0 + 0xD);
      var_v0 = *((u8 *)temp_s0 + 0xE);
      func_80059618(temp_s0, var_a1, var_a2, var_a3, var_v0);
    }
    func_800596F4(temp_s0, *((s16 *)((char *)temp_s0 + 6)), *((s16 *)((char *)temp_s0 + 8)),
                  *((char **)(D_800C02AE + 0x32F2)) + 0x44 + 0x28 * *((u8 *)*((char **)(D_800C02AE + 0x32F2)) + (var_s1 & 0xFF) + 0x32));
    var_s1 += 1;
    var_s2 = *((void **)var_s2);
  } while ((u32)(var_s1 & 0xFF) < (u32)*inline_fn(D_800C02AE));
}
