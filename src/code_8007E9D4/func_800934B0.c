#include "common.h"

typedef struct 
{
  u8 pad00[5];
  u8 b5;
  u8 b6;
  u8 b7;
  u8 b8;
  u8 slot;
  u8 pad0a[2];
  s32 addr;
} Dev;
extern Dev *D_800A2560[4];
extern u8 D_800A7170;
extern u8 D_800A7174;
extern u8 D_A0000000;
void func_800914E0(void *, void *, s32);
s32 func_800934B0(Dev *arg0, s32 arg1, s32 *arg2)
{
  Dev *old;
  s32 a;
  if (arg2 == NULL)
  {
    func_800914E0(&D_800A7170, &D_800A7174, 0x2B);
  }
  if ((*((volatile u32 *) 0xA4600010)) & 3)
  {
    do
    {
    }
    while ((*((volatile u32 *) 0xA4600010)) & 3);
  }
  a = arg0->slot;
  old = D_800A2560[a];
  if (old != arg0)
  {
    if (a == 0)
    {
      if (old->b5 != arg0->b5)
      {
        *((volatile u32 *) 0xA4600014) = arg0->b5;
      }
      if (old->b6 != arg0->b6)
      {
        *((volatile u32 *) 0xA460001C) = arg0->b6;
      }
      if (old->b7 != arg0->b7)
      {
        *((volatile u32 *) 0xA4600020) = arg0->b7;
      }
      if (old->b8 != arg0->b8)
      {
        *((volatile u32 *) 0xA4600018) = arg0->b8;
      }
    }
    else
    {
      if (old->b5 != arg0->b5)
      {
        *((volatile u32 *) 0xA4600024) = arg0->b5;
      }
      if (old->b6 != arg0->b6)
      {
        *((volatile u32 *) 0xA460002C) = arg0->b6;
      }
      if (old->b7 != arg0->b7)
      {
        *((volatile u32 *) 0xA4600030) = arg0->b7;
      }
      if (old->b8 != arg0->b8)
      {
        *((volatile u32 *) 0xA4600028) = arg0->b8;
      }
    }
    D_800A2560[a] = arg0;
  }
  *((s32 *) arg2) = *((volatile s32 *) ((arg0->addr | arg1) | 0xA0000000));
  return 0;
}
