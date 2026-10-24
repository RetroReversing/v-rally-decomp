#include "common.h"

extern char D_800AE850[];
void *func_8003AEF8(void *arg0, void *arg1)
{
  s16 var_v0;
  s32 var_a1;
  u32 temp_a2;
  void *var_v1;
  int new_var;
  temp_a2 = *((u32 *) (((char *) (*((void **) (((char *) arg1) + 0x6C)))) + 8));
  var_a1 = 1;
  if (temp_a2 >= 2U)
  {
    var_a1 = -1;
    var_v0 = (*((u16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x178)))) + 0xA))) + 6;
  }
  else
  {
    var_v0 = (*((u16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x178)))) + 0xA))) + 0x10;
  }
  *((s16 *) (((char *) arg0) + 0xE)) = var_v0;
  var_v1 = *(*((void ***) (D_800AE850 + 0x73F0)));
  if (var_v1 != NULL)
  {
    new_var = temp_a2 + var_a1;
    loop_5:
    if ((*((s32 *) (((char *) (*((void **) (((char *) var_v1) + 0x6C)))) + 8))) != new_var)
    {
      var_v1 = *((void **) (((char *) var_v1) + 4));
      if (var_v1 != NULL)
      {
        goto loop_5;
      }
    }

  }
  return var_v1;
}
