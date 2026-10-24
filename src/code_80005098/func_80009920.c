#include "common.h"

void func_80009920(void *arg0, s32 arg1, s32 arg2, s32 arg3)
{
  void *temp_v1;
  temp_v1 = *((void **) (((s8 *) arg0) + 0x14));
  *((s32 *) (((s8 *) temp_v1) + 0)) = (s32) (((((arg1 & 0x1F) << 0x11) | ((arg2 & 0x1F) << 9)) | ((arg3 & 0x1F) * 2)) | 0x05000000);
  *((s32 *) (((s8 *) temp_v1) + 4)) = 0;
  temp_v1 = (*((void **) (((s8 *) arg0) + 0x14))) + 8;
  *((void **) (((s8 *) arg0) + 0x14)) = (void *) temp_v1;
}
