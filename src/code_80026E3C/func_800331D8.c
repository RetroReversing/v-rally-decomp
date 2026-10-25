#include "common.h"

void func_800331D8(void *arg0)
{
  char *temp_a2;
  s32 x;
  s32 var_a0;
  s8 temp_v1;

  temp_a2 = *((char **) ((char *) arg0 + 0x78));
  x = *((s16 *) (temp_a2 + 4));
  var_a0 = x / 40;
  if (var_a0 >= 0x33)
  {
    var_a0 = 0x32;
  }
  temp_v1 = var_a0 + 0x32;
  *((s8 *) (temp_a2 + 0x14)) = temp_v1;
  *((s8 *) (*((char **) ((char *) arg0 + 0x78)) + 0x17)) = temp_v1;
  *((s8 *) (*((char **) ((char *) arg0 + 0x78)) + 0x15)) = (s8) (0x32 - var_a0);
}
