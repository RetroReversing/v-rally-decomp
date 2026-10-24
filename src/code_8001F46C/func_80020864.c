#include "common.h"

s32 func_80027C64();
void func_80020864(void *arg0)
{
  s32 temp_a0;
  void *temp_v1;
  void *var_s0;
  void *var_s1;
 do { var_s0 = arg0; temp_v1 = *((void **) (((char *) var_s0) + 0x48)); temp_a0 = *((s32 *) (((char *) temp_v1) + 0)); } while (0);
  var_s1 = temp_v1 + 4;
  if (temp_a0 == 7)
  {
    *((s32 *) (((char *) temp_v1) + 0x20)) = temp_a0;
  }
  else
    if ((temp_a0 >= 4) || (!((*((s32 *) (((char *) var_s0) + 0x14))) & 0x300)))
  {
    *((s32 *) (((char *) (*((void **) (((char *) var_s0) + 0x48)))) + 0x20)) = (s32) (func_80027C64(temp_a0 & 0xFFFF) & 0xFFFF);
  }
  *((s8 *) (((char *) var_s1) + 7)) = 0;
}
