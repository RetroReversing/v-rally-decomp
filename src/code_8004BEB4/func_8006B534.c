#include "common.h"

s32 func_8005A360();
s32 func_8006F0E0();
s32 func_8006F75C();
extern void *D_800A1468;
extern char D_800C02AE[];
extern s32 func_80063FFC;
extern s32 func_8006425C;
extern s32 func_80064504;
extern s32 func_8006603C;
extern s32 func_80066384;
extern s32 func_80066470;
extern s32 func_80071B3C;
extern s32 func_80071E08;
extern s32 func_80072364;
static inline void *inline_fn(char *arg0)
{
  return *((void **) arg0);
}

s32 func_8006B534(s32 arg0, s32 arg1)
{
  u16 temp_a0;
  func_8006F0E0(*((u8 *) (((char *) (inline_fn(D_800C02AE + 0x32F2) + (*((s8 *) (((char *) D_800A1468) + 0x228))))) + 0x32)));
  func_8006F75C();
  func_8005A360(arg0, arg1);
  temp_a0 = *((u16 *) (((char *) inline_fn(D_800C02AE + 0x32F2)) + 0x1E));
  if ((temp_a0 != 0) & (temp_a0 < 5U))
  {
    *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_8006603C;
    *((s32 **) (((char *) D_800A1468) + 0x290)) = &func_80066470;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_80066384;
  }
  else
    if (temp_a0 == 0)
  {
    *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_80063FFC;
    *((s32 **) (((char *) D_800A1468) + 0x290)) = &func_8006425C;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_80064504;
  }
  else
    if (temp_a0 == 5)
  {
    *((s32 **) (((char *) D_800A1468) + 0x288)) = &func_80071B3C;
    *((s32 **) (((char *) D_800A1468) + 0x290)) = &func_80071E08;
    *((s32 **) (((char *) D_800A1468) + 0x28C)) = &func_80072364;
  }
  *((s8 *) (((char *) D_800A1468) + 0x22B)) = -1;
  return 1;
}
