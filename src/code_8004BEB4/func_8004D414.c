#include "snapshot31_verified.h"

void func_8004D414(void *arg0)
{
  s16 cnt;
  u16 j;
  u16 i;
  int new_var2;
  u16 found;
  u8 *new_var;
  u8 *inner;
  u8 *ent;
  u8 *obj;
  u32 count;
  count = *((u32 *) (((u8 *) arg0) + 0x50));
  if (count != 0)
  {
    found = (i = 0);
    new_var = *((u8 **) (((u8 *) arg0) + 0x68));
    new_var2 = (*((u32 *) (((u8 *) arg0) + 0x50))) == 0;
    if (new_var2)
    {
      return;
    }
    do
    {
      ent = (u8 *)(((i & 0xffff) * 8) + (s32)new_var);
      ;
      if ((*((s16 *) (ent + 4))) == 0)
      {
        obj = *((u8 **) ent);
        j = 0;
        inner = obj + 0x1c;
        if ((((u32) (*((s16 *) (ent + 4)))) < (*((u16 *) (obj + 0x18)))) && (!found))
        {
          do
          {
            if ((*((u16 *) inner)) == 1)
            {
              found = 1;
              *((u16 *) inner) = 6;
            }
            j++;
            inner += (*((s32 *) (inner + 4))) + 8;
          }
          while ((((u32) (j & 0xffff)) < (*((u16 *) (obj + 0x18)))) && (!found));
        }
      }
      i++;
    }
    while ((((u32) (i & 0xffff)) < (*((u32 *) (((u8 *) arg0) + 0x50)))) && (!found));
  }
}
