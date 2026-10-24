#include "common.h"

s32 func_80021EE4();
void func_80022068(void *arg0, s32 arg1)
{
  s32 new_var;
  s32 temp_a3;
  void *temp_a2;
  void *temp_v0;
  void *temp_v1;
  temp_v0 = *((void **) (((char *) arg0) + 0x80));
  new_var = *((s32 *) (((char *) temp_v0) + 0x18));
  temp_a3 = *((s32 *) (((char *) temp_v0) + 0x40));
  temp_a2 = *((void **) (((char *) arg0) + 0x2C));
  *((s32 *) (((char *) temp_a2) + 0x50)) = (s32) (((arg1 * (new_var - temp_a3)) / 100) + temp_a3);
  temp_v1 = *((void **) (((char *) arg0) + 0x2C));
  *((s32 *) (((char *) temp_v1) + 0x50)) = (s32) ((*((s32 *) (((char *) temp_v1) + 0x50))) << 5);
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x58)))) + 0x50)) = (s32) (*((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x2C)))) + 0x50)));
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x84)))) + 0x48)) = arg1;
  func_80021EE4(arg0, *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x80)))) + 0x388)), temp_a2, temp_a3);
}
