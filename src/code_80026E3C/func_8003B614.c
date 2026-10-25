#include "common.h"

extern s32 D_8009D534;

void func_8003B614(void *arg0)
{
  void *temp_v0;

  temp_v0 = *((void **) (((char *) (*((void **) (((char *) arg0) + 0xA8)))) + 0x24));
  if (temp_v0 != NULL)
  {
    if ((*(*((s32 **) (((char *) (*((void **) (((char *) temp_v0) + 0x6C)))) + 0x24)))) == D_8009D534)
    {
      *((s32 *) (((char *) arg0) + 0x80)) = (*((s32 *) (((char *) arg0) + 0x80))) | 4;
    }
    else
    {
      *((s32 *) (((char *) arg0) + 0x80)) = (*((s32 *) (((char *) arg0) + 0x80))) & ~4;
    }
  }
}
