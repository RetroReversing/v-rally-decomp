#include "common.h"

void func_80080110(void *arg0, void *arg1)
{
  if ((*((void **) (((s8 *) arg1) + 0))) == NULL)
  {
    *((void **) (((s8 *) arg1) + 0)) = arg0;
  }
  else
  {
    *((void **) (((s8 *) (*((void **) (((s8 *) arg1) + 4)))) + 4)) = arg0;
  }
  *((s32 *) (((s8 *) arg0) + 4)) = 0;
  *((void **) (((s8 *) arg0) + 0)) = (void *) (*((void **) (((s8 *) arg1) + 4)));
  *((s16 *) (((s8 *) arg0) + 8)) = 0;
  *((s16 *) (((s8 *) arg0) + 0xA)) = 0;
  *((void **) (((s8 *) arg1) + 4)) = arg0;
}
