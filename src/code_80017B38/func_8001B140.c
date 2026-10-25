#include "common.h"

extern u8 *D_800C7F8C;
extern void *D_800B5B44;
extern void *D_800C3518;
void func_8001A2E0(void *);
void func_8007EE9C(void *);
void func_80005E3C(void *);

void func_8001B140(void)
{
  s32 i;
  s32 count;
  u8 *p;
  u8 *info;
  s32 pad[2];

  info = D_800C7F8C;
  p = *(u8 **)info;
  count = *(u16 *)(info + 4);
  i = 0;
  if (count > 0)
  {
    do
    {
      if (*(void **)(p + 0x38) != NULL)
      {
        func_8001A2E0(p);
        func_8007EE9C(*(void **)(p + 0x38));
      }
      p += 0x3C;
      i++;
    } while (i < *(u16 *)(info + 4));
  }
  func_80005E3C(D_800B5B44);
  D_800B5B44 = NULL;
  D_800C3518 = NULL;
  D_800C7F8C = NULL;
}
