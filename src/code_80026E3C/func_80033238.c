#include "checkpoint_common.h"

void func_80033238(void *arg0)
{
  s32 var_a0;
  s32 temp_v1;
  s8 temp_v0;
  void *temp_a2;

  temp_a2 = *((void **) (((char *) arg0) + 0x78));
  temp_v1 = *((s16 *) (((char *) temp_a2) + 6));
  var_a0 = temp_v1 / 40;
  if (var_a0 >= 0x33)
  {
    var_a0 = 0x32;
  }
  temp_v0 = 0x32 - var_a0;
  *((s8 *) (((char *) temp_a2) + 0x14)) = temp_v0;
  *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x17)) = temp_v0;
  *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x78)))) + 0x16)) = (s8) (var_a0 + 0x32);
}
