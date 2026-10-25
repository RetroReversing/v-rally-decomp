#include "common.h"

void func_8003E06C(void *arg0)
{
  void *temp_v0;
  void *temp_a1;

  temp_v0 = *((void **) (((char *) arg0) + 0xA8));
  temp_v0 = *((void **) (((char *) temp_v0) + 0x24));
  if (temp_v0 != NULL)
  {
    temp_a1 = *((void **) (((char *) temp_v0) + 0x6C));
    if (*((s32 *) (((char *) temp_a1) + 0x20)) == 0)
    {
      if (*((s16 *) (((char *) arg0) + 0x7A)) == *((s32 *) (((char *) temp_a1) + 8)))
      {
        *((u8 *) (((char *) arg0) + 0x90)) = 0xFE;
        *((u8 *) (((char *) arg0) + 0x91)) = 0xD5;
        *((u8 *) (((char *) arg0) + 0x92)) = 0x1E;
        *((u8 *) (((char *) arg0) + 0x93)) = 0xFF;
      }
      else
      {
        *((u8 *) (((char *) arg0) + 0x90)) = 0xFF;
        *((u8 *) (((char *) arg0) + 0x91)) = 0xFF;
        *((u8 *) (((char *) arg0) + 0x92)) = 0xFF;
        *((u8 *) (((char *) arg0) + 0x93)) = 0xFF;
      }
    }
  }
}
