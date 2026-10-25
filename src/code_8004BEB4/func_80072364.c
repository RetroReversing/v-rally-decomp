#include "common.h"

/* identical to func_80064504 (matched), with its names changed by decompdecomp */
void *func_800592AC();
s32 func_80059618();
s32 func_800596F4();
s32 func_8006090C();
s32 func_8006A438();
extern void *D_800C35A0;

void func_80072364(void)
{
  s32 var_s1;
  void *var_s2;
  void *temp_s0;

  var_s2 = func_800592AC(1);
  var_s1 = 0;
  if (((u16 *) (((char *) D_800C35A0) + 0xE))[0] != 0)
  {
    do
    {
      temp_s0 = *((void **) (((char *) var_s2) + 0x28));
      if (*((u8 *) (((char *) var_s2) + 0x42)) != 0)
      {
        func_80059618(temp_s0, 0xDC, 0xDC, 0xE, *((u8 *) (((char *) temp_s0) + 0xE)));
      }
      else
      {
        func_80059618(temp_s0, *((u8 *) (((char *) temp_s0) + 0xB)), *((u8 *) (((char *) temp_s0) + 0xC)), *((u8 *) (((char *) temp_s0) + 0xD)), *((u8 *) (((char *) temp_s0) + 0xE)));
      }
      func_800596F4(temp_s0, *((s16 *) (((char *) temp_s0) + 6)), *((s16 *) (((char *) temp_s0) + 8)), ((char *) D_800C35A0) + (((((u8 *) (((char *) D_800C35A0) + (var_s1 & 0xFF)))[0x32]) * 0x28) + 0x44));
      var_s1 += 1;
      var_s2 = *((void **) var_s2);
    } while ((u8) var_s1 < *((u16 *) (((char *) D_800C35A0) + 0xE)));
  }
  func_8006A438();
  func_8006090C();
}
