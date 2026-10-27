#include "common.h"

u32 osVirtualToPhysical(u32);
void func_80006230(void *arg0)
{
  void *temp_s0;
  temp_s0 = *((void **) (((char *) arg0) + 0x14));
  if (1)
  {
    *((void **) (((char *) arg0) + 0x14)) = (void *) (temp_s0 + 8);
    *((s32 *) (((char *) temp_s0) + 0)) = (s32) ((((0x20 - ((*((u16 *) (((char *) arg0) + 0x7A))) & 0x1F)) & 0xFF) << 0xC) | 0x01000040);
 do { } while (0);
  }
  *((s32 *) (((char *) temp_s0) + 4)) = osVirtualToPhysical((*((s32 *) (((char *) arg0) + 0x70))) + (((*((u16 *) (((char *) arg0) + 0x7A))) * 2) * 8));
}
