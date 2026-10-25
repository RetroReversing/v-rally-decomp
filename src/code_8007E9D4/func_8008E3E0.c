#include "common.h"

void *func_8008EBEC();
void func_8008E3E0(void *arg0, void *arg1, s32 arg2)
{
  s32 var_v1;
  void *var_a0;
  void *var_a2;
  void *var_s0;
  void *var_s1;
  s32 var_s2;
  s32 var_a1;
  var_s0 = arg1;
  var_s1 = arg0;
  var_s2 = arg2;
  if (*((void **) (((char *) var_s0) + 8)) != NULL)
  {
    var_a2 = func_8008EBEC();
    if (var_a2 != NULL)
    {
      var_v1 = *((s32 *) (((char *) var_s1) + 0x1C));
      var_a0 = *((void **) (((char *) *((void **) (((char *) var_s0) + 8))) + 0xD8));
      *((s16 *) (((char *) var_a2) + 8)) = 0x10;
      *((s32 *) (((char *) var_a2) + 0xC)) = var_s2 & 0xFF;
      *((s32 *) (((char *) var_a2) + 0)) = 0;
      var_v1 += (s32) var_a0;
      *((s32 *) (((char *) var_a2) + 4)) = var_v1;
      var_a0 = *((void **) (((char *) *((void **) (((char *) var_s0) + 8))) + 0xC));
      var_a1 = 3;
      (*((s32 (**)(void *, s32, void *)) (((char *) var_a0) + 8)))(var_a0, 3, var_a2);
    }
  }
}
