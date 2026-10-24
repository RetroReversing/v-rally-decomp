#include "common.h"

s32 func_800803C0();
extern char D_800AE850[];
void func_80022214(void)
{
  s32 (*var_v0)();
  void *var_a0;
  void *var_a1;
  void *var_s0;
  void *var_v1;
  var_v1 = D_800AE850 + 0x2370;
  var_v1 = *((void **) (D_800AE850 + 0x2370));
  if (1)
  {
    ;
  }
  if ((*((s32 (**)()) (((char *) var_v1) + 4))) != NULL)
  {
    do
    {
      var_s0 = *((void **) (((char *) var_v1) + 4));
      var_v0 = *((s32 (**)()) (((char *) var_s0) + 0xC));
      var_v0();
      var_a1 = D_800AE850 + 0x2370;
      var_a1 = *((void **) (D_800AE850 + 0x2370));
      var_a0 = var_s0;
 do { } while (0);
      func_800803C0(var_a0, var_a1);
      var_v1 = D_800AE850 + 0x2370;
      var_v1 = *((void **) (D_800AE850 + 0x2370));
      var_v0 = *((s32 (**)()) (((char *) var_v1) + 4));
    }
    while ((*((s32 (**)()) (((char *) var_v1) + 4))) != NULL);
  }
}
