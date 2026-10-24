#include "common.h"

extern int D_800B65EC;
extern int D_800B65F0;
extern int D_800B6AFC;
extern int D_800C34F4;
extern int D_800B65F4;
extern char D_800AE850[];
extern char D_800C02AE[];
void func_8001CC54(void *arg0)
{
  s32 new_var3;
  void *new_var;
  s32 var_a1;
  s32 var_v0;
  s32 var_v1;
  s32 new_var2;
  var_v0 = *((s32 *) (((char *) arg0) + 0x128));
  new_var = arg0;
  new_var2 = *((s32 *) (((char *) new_var) + 0x90));
  var_v1 = new_var2;
  var_a1 = *((s32 *) (((char *) arg0) + 0xDC));
  D_800B65EC = var_v0;
  new_var3 = *((s32 *) (((char *) arg0) + 0x174));
  var_v0 = new_var3;
  D_800B65F0 = var_v0;
  var_v0 = *((s32 *) (((char *) arg0) + 0x1C0));
  D_800B6AFC = var_v1;
  D_800C34F4 = var_a1;
  D_800B65F4 = var_v0;
}
