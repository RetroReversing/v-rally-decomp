#include "common.h"

void *func_8002DA98(void *arg0, void *arg1)
{
  s32 i;
  s32 j;

  ((u16 *)arg1)[0] = ((u16 *)arg0)[0];
  ((u16 *)arg1)[4] = ((u16 *)arg0)[4];
  ((u16 *)arg1)[8] = ((u16 *)arg0)[8];
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)
    {
      ((u16 *)((char *)arg1 + j * 6))[i] = ((u16 *)((char *)arg0 + i * 6))[j];
    }
  }
  ((s32 *)arg1)[5] = ((s32 *)arg0)[5];
  ((s32 *)arg1)[6] = ((s32 *)arg0)[6];
  ((s32 *)arg1)[7] = ((s32 *)arg0)[7];
  return arg1;
}
