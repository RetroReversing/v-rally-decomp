#include "common.h"

s32 func_8005A360();
s32 func_80066B88();
s32 func_8006F0E0();
s32 func_8006F75C();
extern void *D_800A1468;
extern s32 func_80066E20;
extern s32 func_80066EBC;
static inline s8 *inline_fn(char *arg0)
{
  return (s8 *) arg0;
}

s32 func_80067108(s32 arg0, s32 arg1)
{
  char *new_var3;
  char *new_var;
  int new_var2;
  func_80066B88();
  func_8006F0E0(*((u8 *) (((char *) D_800A1468) + 0x228)));
  func_8006F75C();
  func_8005A360(arg0, arg1);
  new_var2 = -1;
  ;
  new_var3 = (char *) D_800A1468;
  *inline_fn(new_var3 + 0x245) = 0;
  new_var = (char *) D_800A1468;
  *((s32 **) (new_var3 + 0x288)) = &func_80066E20;
  *((s32 **) (new_var3 + 0x28C)) = &func_80066EBC;
  *inline_fn(new_var + 0x22B) = new_var2;
  *inline_fn(((char *) D_800A1468) + 0x24D) = 0;
  return 0;
}
