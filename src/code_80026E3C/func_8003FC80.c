#include "common.h"

extern char *D_800B5C40;
extern u8 *D_800C35A0;
void func_8003FC80(void *arg0)
{
  u8 *node;
  u8 *tmp;
  u8 *base;
  u8 *p;
  s32 i;
  s32 key;
  s32 mask;
  s32 new_var;
  i = 0;
  node = *((u8 **) D_800B5C40);
  if (node != NULL)
  {
    mask = ~4;
    key = *((u16 *) (((char *) arg0) + 0x78));
    base = D_800C35A0;
    do
    {
      *((s32 *) (((char *) arg0) + 0x80)) &= mask;
      tmp = *((u8 **) (node + 0x6C));
      new_var = key;
      if ((new_var == (*((s32 *) (tmp + 8)))) && ((*((s32 *) (tmp + 0x20))) == 0))
      {
        p = (base + ((u8) i)) + 0x32;
        *((s16 *) (((char *) arg0) + 0x7A)) = *((u16 *) ((base - (-((*p) * 40))) + 0x4E));
        return;
      }
      node = *((u8 **) (node + 4));
      i++;
    }
    while (node != NULL);
  }
}
