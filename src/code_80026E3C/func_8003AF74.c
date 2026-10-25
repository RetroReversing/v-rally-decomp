#include "common.h"

void *func_8003AEF8();
void func_8003AF74(void *arg0)
{
  void *temp_a1;
  void *temp_v0;
  temp_a1 = *((s32 *) (*((s32 *) (((char *) arg0) + 0xA8)) + 0x24));
  if (temp_a1 != 0)
  {
    temp_a1 = func_8003AEF8(arg0, temp_a1);
    if (temp_a1 != NULL)
    {
      *((s32 *) (((char *) arg0) + 0x80)) = (*((s32 *) (((char *) arg0) + 0x80))) | 4;
      if ((*((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x6C)))) + 0xC))) != 0)
      {
        *((s16 *) (((char *) arg0) + 0x7A)) = 0xB;
        if ((*((s32 *) (((char *) (*((void **) (((char *) temp_a1) + 0x6C)))) + 0x20))) == 0)
        {
          *((u8 *) (((char *) arg0) + 0x90)) = 0xFF;
          *((u8 *) (((char *) arg0) + 0x91)) = 0xFF;
          *((u8 *) (((char *) arg0) + 0x92)) = 0xFF;
          *((u8 *) (((char *) arg0) + 0x93)) = 0xFF;
        }
        *((s32 *) (((char *) arg0) + 0x80)) &= ~4;
      }
    }
  }
}
