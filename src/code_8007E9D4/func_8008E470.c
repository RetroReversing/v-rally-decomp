#include "common.h"

void *__allocParam();
void alSynSetPan(void *arg0, void *arg1, s32 arg2)
{
  s32 (*var_v0)(void *, s32, void *);
  s32 var_a1;
  s32 var_s2;
  s32 var_v1;
  void *var_a0;
  void *var_a2;
  void *var_s0;
  void *var_s1;
  var_s0 = arg1;
  var_v0 = *((s32 (**)(void *, s32, void *)) (((char *) var_s0) + 8));
  var_s1 = arg0;
  var_s2 = arg2;
  if (var_v0 != NULL)
  {
    var_a2 = __allocParam();
    if (var_a2 != NULL)
    {
      var_v0 = *((s32 (**)(void *, s32, void *)) (((char *) var_s0) + 8));
      var_v1 = *((s32 *) (((char *) var_s1) + 0x1C));
      var_a0 = *((void **) (((char *) var_v0) + 0xD8));
      var_v0 = (s32 (*)(void *, s32, void *)) 0xC;
      *((s16 *) (((char *) var_a2) + 8)) = 0xC;
      do
      {
        var_v0 = (s32 (*)(void *, s32, void *)) (var_s2 & 0xFF);
 do { *((s32 (**)(void *, s32, void *)) (((char *) var_a2) + 0xC)) = var_v0; *((s32 *) (((char *) var_a2) + 0)) = 0; } while (0);
        var_v1 += var_a0;
        *((s32 *) (((char *) var_a2) + 4)) = var_v1;
      }
      while (0);
      var_v0 = *((s32 (**)(void *, s32, void *)) (((char *) var_s0) + 8));
      var_a0 = *((void **) (((char *) var_v0) + 0xC));
      var_v0 = *((s32 (**)(void *, s32, void *)) (((char *) var_a0) + 8));
      var_a1 = 3;
      var_v0(var_a0, 3, var_a2);
    }
  }
}
